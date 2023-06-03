#include <SFML/Graphics.hpp>
using namespace sf;

const Color BACKGROUND = Color(79, 79, 79);
const Color BOTON = Color(150, 150, 150);

int main(){
    RenderWindow window(VideoMode(350, 450), "Calculadora", Style::Titlebar | Style::Close);
    RectangleShape background_operator(Vector2f(350, 100));
    while(window.isOpen()){
        Event evento;
        while(window.pollEvent(evento)){
            if(evento.type == Event::Closed){
                window.close();
            }
        }
        window.clear(BACKGROUND);
        window.draw(background_operator);
        window.display();
    }
    return EXIT_SUCCESS;
}