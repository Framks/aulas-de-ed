#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // cria uma tela sem ser o terminal ( ou melhor cria uma janela)
    sf::RenderWindow window(sf::VideoMode(1360, 768), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
    sf::Text texto;
    sf::Font font;
    if(!font.loadFromFile("stocky.ttf")){
        return EXIT_FAILURE;
    }
    texto.setFont(font);
    texto.setCharacterSize(20);
    texto.setFillColor(sf::Color::White);   
    // enquanto a tela estiver aberta 
    while (window.isOpen())
    {
        // cria um evento 
        sf::Event evento;
        while (window.pollEvent(evento))
        {
            // se o evento for fechado ele fecha a janela
            if (evento.type == sf::Event::Closed)
                window.close();
                        
            // se o evento for pressionado Por alguma tecla do teclado
            if(evento.type == sf::Event::KeyPressed){
                
                // se a tecla for A
                if(evento.key.code == sf::Keyboard::A){
                    texto.setString("A");
                    texto.setPosition(texto.getPosition().x +10, texto.getPosition().y);
                }
            }
            if(evento.type == sf::Event::KeyPressed){
                
                // se a tecla for A
                if(evento.key.code == sf::Keyboard::S){
                    texto.setString("S");
                    texto.setPosition(texto.getPosition().x +10, texto.getPosition().y);
                }
            }
            if(evento.type == sf::Event::KeyPressed){
                
                // se a tecla for A
                if(evento.key.code == sf::Keyboard::D){
                    texto.setString("D");
                    texto.setPosition(texto.getPosition().x +10, texto.getPosition().y);
                }
            }
            if(evento.type == sf::Event::KeyPressed){
                
                // se a tecla for A
                if(evento.key.code == sf::Keyboard::W){
                    texto.setString("W");
                    texto.setPosition(texto.getPosition().x +10, texto.getPosition().y);
                }
            }
        }
        window.clear();
        window.draw(texto);
        window.display();
    }
    return 0;
}

/*
int main(){

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    sf::Text texto;
    sf::Font font;
    shape.setFillColor(sf::Color::Green);
    if(!font.loadFromFile("stocky.ttf")){
        return EXIT_FAILURE;
    }
    texto.setString("JOGO DA COBRINHA");
    texto.setFont(font);
    texto.setCharacterSize(19);
    texto.setFillColor(sf::Color::White);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw(texto);
        window.display();
    }

    return EXIT_SUCCESS;
}
*/