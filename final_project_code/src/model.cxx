#include "model.hxx"

using namespace ge211;


Scene::Scene(Dimensions dims)
    : scene_dims(dims)
{
    if (dims.width < 2 || dims.height < 2) {
        throw Client_logic_error("Scene::Scene: dimensions too small");
    }

    if (dims.width > 120 || dims.height > 120) {
        throw Client_logic_error("Scene::Scene: dimensions too large");
    }
}

Scene::Dimensions
Scene::dimensions() const
{
    return scene_dims;
}

bool
Scene::good_position(Position pos) const
{
    return 0 <= pos.x && pos.x < scene_dims.width &&
           0 <= pos.y && pos.y < scene_dims.height;
}

void
Scene::bounds_check(Position pos) const
{
    if (!good_position(pos)) {
        throw Client_logic_error("Scene: position out of bounds");
    }
}

///--------------------------------------------------------------------------///

static int const scene_multiplier = 12;

Model::Model(int size)
        : Model(size,size)
{ }

Model::Model(int width, int height)
    : game_scene({width,height})
{ }

Model::Dimensions
Model::Dims() const
{
    return game_scene.dimensions();
}

Model::Position
Model::operator[](Position pos) const
{
    game_scene.bounds_check(pos);
    return pos;
}

bool
Model::easy_click(Position pos) const
{
    Dimensions buttom_dims = {this->Dims().width * 3 , this->Dims().height};
    Dimensions window_dims = scene_multiplier * this->Dims();

    bool result;

    int x = window_dims.width / 2;
    int y = window_dims.height / 2;
    Position center = {x,y};

    Position e_coord = {center.left_by(this->Dims().width * 1.5)
                              .up_by(this->Dims().height * 1.25)};

    Rectangle e_button(e_coord.x, e_coord.y,
                       buttom_dims.width,buttom_dims.height);

    // Cursor edges
    int r_cursor = pos.x + (scene_multiplier / 2);
    int l_cursor = pos.x - (scene_multiplier / 2);
    int t_cursor = pos.y - (scene_multiplier / 2);
    int b_cursor = pos.y + (scene_multiplier / 2);

    // Easy Button Edges
    int r_easy = e_coord.x + e_button.width;
    int l_easy = e_coord.x;
    int t_easy = e_coord.y;
    int b_easy = e_coord.y + e_button.height;

    bool cond1 = r_cursor < l_easy;
    bool cond2 = l_cursor > r_easy;
    bool cond3 = t_cursor > b_easy;
    bool cond4 = b_cursor < t_easy;

    if (cond1 || cond2 || cond3 || cond4){
        result = false;
    } else {
        result = true;
    }

    return result;
}


bool
Model::med_click(Position pos) const
{
        Dimensions buttom_dims = {this->Dims().width * 3 , this->Dims().height};
        Dimensions window_dims = scene_multiplier * this->Dims();

        bool result;

        int x = window_dims.width / 2;
        int y = window_dims.height / 2;
        Position center = {x,y};

        Position m_coord ={center.left_by(this->Dims().width * 1.5)
                                 .up_by(0)};

        Rectangle m_button(m_coord.x, m_coord.y,
                           buttom_dims.width,buttom_dims.height);

        // Cursor edges
        int r_cursor = pos.x + (scene_multiplier / 2);
        int l_cursor = pos.x - (scene_multiplier / 2);
        int t_cursor = pos.y - (scene_multiplier / 2);
        int b_cursor = pos.y + (scene_multiplier / 2);

        // Medium Button Edges
        int r_med = m_coord.x + m_button.width;
        int l_med = m_coord.x;
        int t_med = m_coord.y;
        int b_med = m_coord.y + m_button.height;

        bool cond1 = r_cursor < l_med;
        bool cond2 = l_cursor > r_med;
        bool cond3 = t_cursor > b_med;
        bool cond4 = b_cursor < t_med;

        if (cond1 || cond2 || cond3 || cond4){
            result = false;
        } else {
            result = true;
        }

        return result;
}

bool
Model::hard_click(Position pos) const
{

        Dimensions buttom_dims = {this->Dims().width * 3 , this->Dims().height};
        Dimensions window_dims = scene_multiplier * this->Dims();

        bool result;

        int x = window_dims.width / 2;
        int y = window_dims.height / 2;
        Position center = {x,y};

        Position h_coord = {center.left_by(this->Dims().width * 1.5)
                                  .down_by(this->Dims().height * 1.25)};

        Rectangle h_button(h_coord.x, h_coord.y,
                           buttom_dims.width,buttom_dims.height);


        // Cursor edges
        int r_cursor = pos.x + (scene_multiplier / 2);
        int l_cursor = pos.x - (scene_multiplier / 2);
        int t_cursor = pos.y - (scene_multiplier / 2);
        int b_cursor = pos.y + (scene_multiplier / 2);

        // Hard Button Edges
        int r_hard = h_coord.x + h_button.width;
        int l_hard = h_coord.x;
        int t_hard = h_coord.y;
        int b_hard = h_coord.y + h_button.height;

        bool cond1 = r_cursor < l_hard;
        bool cond2 = l_cursor > r_hard;
        bool cond3 = t_cursor > b_hard;
        bool cond4 = b_cursor < t_hard;

        if (cond1 || cond2 || cond3 || cond4){
            result = false;
        } else {
            result = true;
        }

        return result;
}

Model::Position
Model::random_spot(int radius, Dimensions dims) const
{
    int width = dims.width;
    int height = dims.height;

    ge211::Random_source<int> x_rand(0,width);
    ge211::Random_source<int> y_rand(0,height);

    int x = x_rand.next();
    int y = y_rand.next();

    bool cond1 = (x + (2 * radius)) > width;
    bool cond2 = (y + (2 * radius)) > height;

    while (cond1 || cond2) {
        if (cond1) {
            x = x_rand.next();
        } else if (cond2) {
            y = y_rand.next();
        } else {
            break;
        }
    }

    return {x,y};
}

bool
Model::game_over(int time, int lives) const
{
    bool result = false;

    if (time == 0) {
        result = true;
    } else if (lives == 0) {
        result = true;
    }

    return result;

}

//void
//Model::target_animation(int time, int gamemode) const
//{
//    if
//
//}


