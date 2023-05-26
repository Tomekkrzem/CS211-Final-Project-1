#include "view.hxx"

using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;

// Use this to Make Game Larger
static int const scene_multiplier = 12;

View::View(Model const& model)
        : model_(model),
          showMainMenu(true),

          menu_sprite(initial_window_dimensions(),{0,25,51}),
          title_text(),
          hard_sprite({model_.Dims().width * 3,model_.Dims().height},
                      {255,0,0}),
          medium_sprite({model_.Dims().width * 3,model_.Dims().height},
                        {255,255,0}),
          easy_sprite({model_.Dims().width * 3,model_.Dims().height},
                      {0,255,0}),
          h_hover_sprite({model_.Dims().width * 3,model_.Dims().height},
                      {153,0,0}),
          m_hover_sprite({model_.Dims().width * 3,model_.Dims().height},
                      {153,153,0}),
          e_hover_sprite({model_.Dims().width * 3,model_.Dims().height},
                      {0,153,0}),
          crosshair_sprite(scene_multiplier / 2 ,
                           {255, 255, 255}),
          game_board_sprite(initial_window_dimensions(),{0,0,0}),
          target_sprite("target_.png")


{ }

void
View::draw(ge211::Sprite_set& set)
{
    // Title Builder
    ge211::Text_sprite::Builder name_builder(font_info);

    // Set Title color
    name_builder.color({0,255,250}) << "HITS";

    // Updates the title_text sprite
    title_text.reconfigure(name_builder);

    // Finds approximate center
    int x = initial_window_dimensions().width / 2;
    int y =initial_window_dimensions().height / 2;
    Position center = {x,y};

    if (showMainMenu) {
        set.add_sprite(menu_sprite, {0, 0});
        set.add_sprite(title_text,
                       {center.left_by(model_.Dims().width * 2.25)
                              .up_by(model_.Dims().height * 6)}, 2);

        set.add_sprite(easy_sprite,
                       {center.left_by(model_.Dims().width * 1.5)
                              .up_by(model_.Dims().height * 1.25)}, 2);

        set.add_sprite(medium_sprite,
                       {center.left_by(model_.Dims().width * 1.5)
                              .up_by(0)}, 2);

        set.add_sprite(hard_sprite,
                       {center.left_by(model_.Dims().width * 1.5)
                              .down_by(model_.Dims().height * 1.25)}, 2);
    }

    ge211::Transform target = ge211::Transform{}
    .set_scale_x(0.2)
    .set_scale_y(0.2);

    if (!showMainMenu) {
        set.add_sprite(target_sprite,
                       center.left_by(model_.Dims().width)
                       .up_by(model_.Dims().height),5,target);
    }

    // if (!showMainMenu) {
    //     set.add_sprite(target_sprite,model_.random_spot
    //     (target_sprite.dimensions().width,
    //      initial_window_dimensions()),5,target);
    // }

}

View::Dimensions
View::initial_window_dimensions() const
{
    return scene_multiplier * model_.Dims();
}

void
View::draw_input(ge211::Sprite_set& set, ge211::Posn<int> mouse_posn)
{
    int x = initial_window_dimensions().width / 2;
    int y = initial_window_dimensions().height / 2;

    Position center = {x, y};

    set.add_sprite(crosshair_sprite,
                   mouse_posn.left_by(scene_multiplier / 2)
                             .up_by(scene_multiplier / 2), 9);
    if (showMainMenu) {
        if (model_.easy_click(mouse_posn)) {
            set.add_sprite(e_hover_sprite,
                           {center.left_by(model_.Dims().width * 1.5)
                                  .up_by(model_.Dims().height * 1.25)}, 3);
        } else {
            set.add_sprite(easy_sprite,
                           {center.left_by(model_.Dims().width * 1.5)
                                  .up_by(model_.Dims().height * 1.25)}, 2);
        }

        if (model_.med_click(mouse_posn)) {
            set.add_sprite(m_hover_sprite,
                           {center.left_by(model_.Dims().width * 1.5)
                                  .up_by(0)}, 3);
        } else {
            set.add_sprite(medium_sprite,
                           {center.left_by(model_.Dims().width * 1.5)
                                  .up_by(0)}, 2);
        }

        if (model_.hard_click(mouse_posn)) {
            set.add_sprite(h_hover_sprite,
                           {center.left_by(model_.Dims().width * 1.5)
                                  .down_by(model_.Dims().height * 1.25)}, 3);
        } else {
            set.add_sprite(hard_sprite,
                           {center.left_by(model_.Dims().width * 1.5)
                                  .down_by(model_.Dims().height * 1.25)}, 2);
        }
    }


}

void
View::button_input(ge211::Sprite_set& set, View::Position mouse_posn)
{
    if (model_.easy_click(mouse_posn)) {
        set.add_sprite(game_board_sprite,{0,0},4);
        showMainMenu = false;
    }

    if (model_.med_click(mouse_posn)) {
        set.add_sprite(game_board_sprite,{0,0},4);
        showMainMenu = false;
    }

    if (model_.hard_click(mouse_posn)) {
        set.add_sprite(game_board_sprite,{0,0},4);
        showMainMenu = false;
    }
}

void
View::target_click(ge211::Sprite_set&, View::Position mouse_posn)
{

}

