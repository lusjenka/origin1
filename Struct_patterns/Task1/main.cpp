#include <iostream>

class Simple_text {
public:
    virtual void render(const std::string& data) const {

        std::cout << data;
    }
};

class Decorated_text : public Simple_text {
public:
    Decorated_text(Simple_text* _text) : text(_text) {}
    Simple_text* text;
};

class Paragraph : public Decorated_text {

public:
    Paragraph(Simple_text* _text) : Decorated_text(_text) {}
    void render(const std::string data) {
        std::cout << "<p>";
        text->render(data);
        std::cout << "</p>";
    }
};

class Reversed : public Decorated_text {

public:
    Reversed(Simple_text* _text) : Decorated_text(_text) {}
    void render(std::string data) {
        std::reverse(data.begin(), data.end());
        text->render(data);
    }
};

class Link : public Decorated_text {

public:
    Link(Simple_text* _text) : Decorated_text(_text) {}
    void render(std::string Link_, const std::string data) {
        std::cout << "<a href=" << Link_ << ">";
        text->render(data);
        std::cout << "</a>";
    }
};

int main()
{
    auto text_block1 = new Paragraph(new Simple_text());
    text_block1->render("Hello world");
    std::cout << std::endl;

    auto text_block3 = new Reversed(new Simple_text());
    text_block3->render("Hello world");
    std::cout << std::endl;

    auto text_block2 = new Link(new Simple_text());
    text_block2->render("netology.ru", "Hello world");

    return 0;
}