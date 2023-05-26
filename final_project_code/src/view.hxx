#pragma once

#include "model.hxx"

#include <string>

class View
{
public:
    /// View dimensions will use `int` coordinates.
    using Dimensions = ge211::Dims<int>;

    /// View positions will use `int` coordinates.
    using Position = ge211::Posn<int>;

    /// View rectangles will use `int` coordinates.
    using Rectangle = ge211::Rect<int>;

    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set);

    Dimensions initial_window_dimensions() const;

    void draw_input(ge211::Sprite_set&, Position mouse_posn);

    void button_input(ge211::Sprite_set&, Position mouse_posn);

    void target_click(ge211::Sprite_set&, Position mouse_posn);


private:
    Model const& model_;
    bool showMainMenu;

    ge211::Rectangle_sprite menu_sprite;

    ge211::Text_sprite title_text;
    ge211::Font font_info{"GamePlayedOutline-wrX8.ttf",
                          (initial_window_dimensions().height
                          / model_.Dims().height) * 20};

    // Main Button Sprites
    ge211::Rectangle_sprite hard_sprite;
    ge211::Rectangle_sprite medium_sprite;
    ge211::Rectangle_sprite easy_sprite;

    // Button Sprites darken when cursor hovers over them
    ge211::Rectangle_sprite h_hover_sprite;
    ge211::Rectangle_sprite m_hover_sprite;
    ge211::Rectangle_sprite e_hover_sprite;

    // Constant Cursor Sprite for Game
    ge211::Circle_sprite crosshair_sprite;

    // Main Game Background
    ge211::Rectangle_sprite game_board_sprite;

    // Target Sprite
    ge211::Image_sprite target_sprite;
};
