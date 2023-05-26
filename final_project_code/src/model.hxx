#pragma once

#include <ge211.hxx>


class Scene
{
public:
    /// Scene dimensions will use `int` coordinates.
    using Dimensions = ge211::Dims<int>;

    /// Scene positions will use `int` coordinates.
    using Position = ge211::Posn<int>;

    /// Scene rectangles will use `int` coordinates.
    using Rectangle = ge211::Rect<int>;

    bool good_position(Position) const;

    void bounds_check(Position) const;

private:

    Dimensions scene_dims;

public:

    explicit Scene(Dimensions dims);

    Dimensions dimensions() const;
};

class Model
{
public:
    using Dimensions = Scene::Dimensions;

    using Position = Scene::Position;

    using Rectangle = Scene::Rectangle;

    explicit Model(int size = 100);

    Model(int width, int height);

    Dimensions Dims() const;

    Position operator[](Position) const;

    bool easy_click(Position) const;

    bool med_click(Position) const;

    bool hard_click(Position) const;

    Position random_spot(int radius, Dimensions dims) const;

    bool game_over(int time, int lives) const;

    bool hit_target(Position) const;

    void target_animation(int time, int gamemode) const;

private:
    Scene game_scene;
    bool button_on;
};