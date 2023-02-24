#include "GameUtilities/Window/Window.h"
#include "GameUtilities/Event/Events/Event.h"
#include "GameUtilities/Event/EventId.h"
#include "GameUtilities/Event/Events.h"
#include "GameUtilities/Event/Events/Keyboard/KeyboardId.h"
#include <Math/Vector2.h>
#include <cassert>

int main()
{
    Math::Vector2<float> size(400, 400);
    GU::Win::Window win(size);
    win.setTitle("Example");
    win.setSize({800, 600});
    win.setPosition({500, 200});
    win.show();    

    while(win.isOpen())
    {
        std::shared_ptr<GU::Evt::Event> base = nullptr; 
        if(win.poll(base))
        {
            assert(base != nullptr);
            switch(base->getId())
            {
                case GU::Evt::EventId::ON_KEY_PRESSED:
                    std::shared_ptr<GU::Evt::OnKeyPressed> event = std::dynamic_pointer_cast<GU::Evt::OnKeyPressed>(base);  
                    assert(event != nullptr);
                    //std::cout << "Key = " << event->m_keyId << std::endl; 
                    switch(event->m_keyId)
                    {
                        case GU::Evt::KeyboardId::A:
                            std::cout << "A";
                        break;
                        case GU::Evt::KeyboardId::B:
                            std::cout << "B";
                        break;
                        case GU::Evt::KeyboardId::C:
                            std::cout << "C";
                        break;
                        case GU::Evt::KeyboardId::D:
                            std::cout << "D";
                        break;
                        case GU::Evt::KeyboardId::E:
                            std::cout << "E";
                        break;
                        case GU::Evt::KeyboardId::F:
                            std::cout << "F";
                        break;
                        case GU::Evt::KeyboardId::G:
                            std::cout << "G";
                        break;
                        case GU::Evt::KeyboardId::H:
                            std::cout << "H";
                        break;
                        case GU::Evt::KeyboardId::I:
                            std::cout << "I";
                        break;
                        case GU::Evt::KeyboardId::J:
                            std::cout << "J";
                        break;
                        case GU::Evt::KeyboardId::K:
                            std::cout << "K";
                        break;
                        case GU::Evt::KeyboardId::L:
                            std::cout << "L";
                        break;
                        case GU::Evt::KeyboardId::M:
                            std::cout << "M";
                        break;
                        case GU::Evt::KeyboardId::N:
                            std::cout << "N";
                        break;
                        case GU::Evt::KeyboardId::O:
                            std::cout << "O";
                        break;
                        case GU::Evt::KeyboardId::P:
                            std::cout << "P";
                        break;
                        case GU::Evt::KeyboardId::Q:
                            std::cout << "Q";
                            win.close();
                        break;
                        case GU::Evt::KeyboardId::R:
                            std::cout << "R";
                        break;
                        case GU::Evt::KeyboardId::S:
                            std::cout << "S";
                        break;
                        case GU::Evt::KeyboardId::T:
                            std::cout << "T";
                        break;
                        case GU::Evt::KeyboardId::U:
                            std::cout << "U";
                        break;
                        case GU::Evt::KeyboardId::V:
                            std::cout << "V";
                        break;
                        case GU::Evt::KeyboardId::W:
                            std::cout << "W";
                        break;
                        case GU::Evt::KeyboardId::X:
                            std::cout << "X";
                        break;
                        case GU::Evt::KeyboardId::Y:
                            std::cout << "Y";
                        break;
                        case GU::Evt::KeyboardId::Z:
                            std::cout << "Z";
                        break;
                        case GU::Evt::KeyboardId::ONE:
                            std::cout << "1";
                        break;
                        case GU::Evt::KeyboardId::TWO:
                            std::cout << "2";
                        break;
                        case GU::Evt::KeyboardId::THREE:
                            std::cout << "3";
                        break;
                        case GU::Evt::KeyboardId::FOUR:
                            std::cout << "4";
                        break;
                        case GU::Evt::KeyboardId::FIVE:
                            std::cout << "5";
                        break;
                        case GU::Evt::KeyboardId::SIX:
                            std::cout << "6";
                        break;
                        case GU::Evt::KeyboardId::SEVEN:
                            std::cout << "7";
                        break;
                        case GU::Evt::KeyboardId::EIGHT:
                            std::cout << "8";
                        break;
                        case GU::Evt::KeyboardId::NINE:
                            std::cout << "9";
                        break;
                        case GU::Evt::KeyboardId::ZERO:
                            std::cout << "0";
                        break;
                        case GU::Evt::KeyboardId::RETURN:
                            std::cout << "\n";
                        break;
                        case GU::Evt::KeyboardId::SPACE:
                            std::cout << " ";
                        break;
                        case GU::Evt::KeyboardId::LEFT_SHIFT:
                            std::cout << "Left Shift";
                        break;
                        case GU::Evt::KeyboardId::RIGHT_SHIFT:
                            std::cout << "Right Shift";
                        break;
                        case GU::Evt::KeyboardId::LEFT_CTRL:
                            std::cout << "Left Ctrl";
                        break;
                        case GU::Evt::KeyboardId::RIGHT_CTRL:
                            std::cout << "Right Ctrl";
                        break;
                        case GU::Evt::KeyboardId::LEFT_ALT:
                            std::cout << "Left Alt";
                        break;
                        case GU::Evt::KeyboardId::RIGHT_ALT:
                            std::cout << "Right Alt";
                        break;
                        case GU::Evt::KeyboardId::META:
                            std::cout << "Meta";
                        break;
                        case GU::Evt::KeyboardId::ESC:
                            std::cout << "Esc";
                        break;
                        case GU::Evt::KeyboardId::UP_ARROW:
                            std::cout << "Up Arrow";
                        break;
                        case GU::Evt::KeyboardId::DOWN_ARROW:
                            std::cout << "Down Arrow";
                        break;
                        case GU::Evt::KeyboardId::LEFT_ARROW:
                            std::cout << "Left Arrow";
                        break;
                        case GU::Evt::KeyboardId::RIGHT_ARROW:
                            std::cout << "Right Arrow";
                        break;
                        case GU::Evt::KeyboardId::BACKSPACE:
                            std::cout << "Backspace";
                        break;
                        default:
                        { 
                            std::cout << "Error unhandled keyboard id " << event->m_keyId << std::endl;
                        }
                    }; 
                    std::cout << std::flush;
                break;
            };
        }
   } 
    return 0;
}
