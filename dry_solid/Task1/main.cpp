class Printable
{
public:
    virtual ~Printable() = default;
    virtual std::string printAsHTML() const = 0;
    virtual std::string printAsText() const = 0;
    virtual std::string printAsJSON() const = 0;
};

//����� Printable �������� ������� ���������� �����������, ��� ����� ���������� � ������� ��������� ������ ��� ������� ���� ������, �.�.� ������� ���� ��������� ����� ��� ����� ��� ������, �� ������� �������� ������ ����������, ��� ��� ������� ������� ���������� / ����������.

std::string printAsHTML() const override
{
    if (format_ != Format::kHTML) {
        throw std::runtime_error("Invalid format!");
    }
    return "<html>" + data_ + "<html/>";
}
std::string printAsText() const override
{
    if (format_ != Format::kText) {
        throw std::runtime_error("Invalid format!");
    }
    return data_;
}
std::string printAsJSON() const override
{
    if (format_ != Format::kJSON) {
        throw std::runtime_error("Invalid format!");
    }
    return "{ \"data\": \"" + data_ + "\"}";
}

//� ������ Data ������� ������� ����������� ������� ������, �.�.������� printAsHTML() printAsText() printAsJSON() ������ ���������� ������� ���� std::string, � ���������� ������� ������.


void saveTo(std::ofstream& file, const Printable& printable, Data::Format format)
{
    switch (format)
    {
    case Data::Format::kText:
        file << printable.printAsText();
        break;
    case Data::Format::kJSON:
        file << printable.printAsJSON();
        break;
    case Data::Format::kHTML:
        file << printable.printAsHTML();
        break;
    }
}

//� ������� saveTo ������� ������� ���������� / ����������, ����� ������� ��������� ����� � �������� ��� ���������� ��� ������ ��� ������