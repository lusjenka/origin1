class Printable
{
public:
    virtual ~Printable() = default;
    virtual std::string printAsHTML() const = 0;
    virtual std::string printAsText() const = 0;
    virtual std::string printAsJSON() const = 0;
};

//Класс Printable нарушает принцип разделения интерфейсов, его лучше разгрузить и создать отдельные классы для каждого типа данных, т.к.в будущем если добавится новый тип файла для печати, то придётся изменять калссы наследники, что уже нарушит принцип открытости / закрытости.

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

//В классе Data нарушен принцип подстановки Барбары Лисков, т.к.функции printAsHTML() printAsText() printAsJSON() должны возвращать объекты типа std::string, а возвращают простро строку.


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

//В функции saveTo нарушен принцип открытости / закрытости, лучше создать отдельный класс с функцией для сохранения под каждый тип данных