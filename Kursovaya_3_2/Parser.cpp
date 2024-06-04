#include "parser.h"


iniParser::iniParser(const std::string& filename) : filename_{ filename }//����������� ��������� ������ �� ���� ���

{
    std::ifstream file(filename_);//��������� ���� ��� ������

    if (!file.is_open())//���� ������, �� �������� ����������
    {
        throw std::runtime_error("������ �������� �����: " + filename_);
    }

    while (std::getline(file, line_)) // ���� ���� �� �������� ������ � ���������� line_
    {
        // ���������� ����������� � ������ ������
        if (line_.empty() || line_[0] == ';')
        {
            ++lineNumber_;//���� ����� ��� �����������, �� ����������� lineNumber_ �� 1
            continue;//������� ��������� �������� ������
        }

        // ������� ����� ������
        if ((line_[0] == '[') && (line_[line_.length() - 1] == ']'))//���� ����� ������
        {
            ++lineNumber_;//������� � ������
            // ������ ����� ������
            currentSection_ = line_.substr(1, line_.length() - 2);//� currentSection_ ���������� ��������� ������
        }
        else // ���� �� ����� ������
        {
            ++lineNumber_;
            // ������� ������ � ������ � ���������
            std::istringstream iss(line_);//����������� �����??

            if (std::getline(iss, key_, '='))//������ line_ ���������� � key_ ���� �� �������� = (���� ; ������ =)
            {
                if (key_ == "")//���� value_ ������ key_
                {
                    //std::cout << "key_: " << key_ << std::endl;
                    //throw std::runtime_error("��� �������� ���������� � " + currentSection_ + " � ������ � " + std::to_string(lineNumber_));
                }
                

                if (std::getline(iss, value_))//������ ������ line_ ����� =
                {
                    size_t pos = value_.find(';');  // ������� ������� ������� ��������� ����� ";"

                    if (pos != std::string::npos) // ���� ���� ������
                    {
                        value_ = value_.substr(0, pos);  // �������� ������, �������� ������ ����� �� ����� ";"
                    }
                    iniData_[currentSection_][key_] = value_;//���������� � ��� [��������� ������][����] = �������� ���������
                }
            }
        }
    }
    file.close();
}

std::string iniParser::getStringValue(const std::string currentSection, const std::string key, const int lineNumber)
{
    std::map<std::string, std::map<std::string, std::string>>::iterator it1 = iniData_.find(currentSection);
    if (it1 == iniData_.end())
    {
        printMap(currentSection, key);
        throw std::runtime_error(currentSection + " �� �������");
    }
    else
    {
        std::map<std::string, std::string>& innerMap = iniData_[currentSection];
        if (!innerMap.count(key))
        {
            printMap(currentSection, key);
            throw std::runtime_error("");
        }
    }
    return iniData_[currentSection][key];
}

void iniParser::printMap(const std::string currentSection, const std::string key)
{
    std::cout << "��� ��������: " + key + ", � ������ " + currentSection << std::endl;
  
}