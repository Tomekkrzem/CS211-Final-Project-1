#include "model.hxx"
#include <catch.hxx>

TEST_CASE("example test (TODO: replace this)")
{
    CHECK(1 + 1 == 2);
}

TEST_CASE("Button Click Test")
{
    Model model_;
    ge211::Posn<int> pos = {0,0};

    CHECK_FALSE(model_.easy_click(pos));

    CHECK_FALSE(model_.med_click(pos));

    CHECK_FALSE(model_.hard_click(pos));

    CHECK(model_.random_spot(6,model_.Dims()).x == 0);
    CHECK(model_.random_spot(6,model_.Dims()).y == 0);
}


//
// TODO: Write preliminary model tests.
//
// These tests should demonstrate your functional requirements.
//
