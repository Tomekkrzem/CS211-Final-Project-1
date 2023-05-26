#include "controller.hxx"


Controller::Controller(int size)
        : Controller(size,size)
{ }

Controller::Controller(int width, int height)
        : model_(width, height),
          view_(model_),
          cursor(0,0),
          click(0,0)

{}

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
    view_.draw_input(set,cursor);
    view_.button_input(set,click);


}

View::Dimensions
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

void Controller::on_mouse_move(ge211::Posn<int> pos)
{
    cursor = pos;
}

void
Controller::on_mouse_up(ge211::Mouse_button, ge211::Posn<int> pos)
{
    click = pos;
}

// void
// Controller::on_key(ge211::Key key)
// {
//     if (key == ge211::Key::code('q')) {
//         view_.showMainMenu = true;
//     }
// }