#include "doctest.h"

#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"
#include <random>
#include <chrono>

using namespace ariel;
using namespace std;

TEST_CASE("Test Point") {
    Point p1(6,10);
    Point p2(2, 7);
    CHECK_EQ(p1.distance(p2), 5.0);
}

TEST_CASE("Test Character") {
    Point p1(2, 2);
    Character character(p1, 110, "Naor");

    CHECK_EQ(character.getName(), "Naor");
    CHECK_EQ(character.getLocation().GetX(), 2);
    CHECK_EQ(character.getLocation().GetY(), 2);
    CHECK_EQ(character.getPoints(), 110);
    CHECK_EQ(character.isAlive(), true);
}

TEST_CASE("Test Ninja ") {
    Ninja ninja("Naruto", Point(1,1), 110, 14);

    CHECK_EQ(ninja.getName(), "Naruto");
    CHECK_EQ(ninja.getLocation().GetX(), 1);
    CHECK_EQ(ninja.getLocation().GetY(), 1);
    CHECK_EQ(ninja.getPoints(), 110);
    CHECK_EQ(ninja.isAlive(), true);
}

TEST_CASE("Test Cowboy ") {
    Cowboy cowboy("Otis", Point(1,1));

    CHECK_EQ(cowboy.getName(), "Otis");
    CHECK_EQ(cowboy.getLocation().GetX(), 1);
    CHECK_EQ(cowboy.getLocation().GetY(), 1);
    CHECK_EQ(cowboy.isAlive(), true);
    CHECK(cowboy.hasboolets());

    SUBCASE("Test Shoot") {
        Cowboy cowboy2("Otis2", Point(1, 1));
        cowboy.shoot(&cowboy2);
        cowboy.shoot(&cowboy2);
        cowboy.shoot(&cowboy2);
        cowboy.shoot(&cowboy2);
        cowboy.shoot(&cowboy2);
        cowboy.shoot(&cowboy2);
        CHECK_FALSE(cowboy.hasboolets()); 
    }
}

TEST_CASE("Test OldNinja") {
    OldNinja oldNinja("Senin", Point(1,1));
    OldNinja oldNinja2("Senin2", Point(0,0));

    CHECK_EQ(oldNinja.getName(), "Senin");
    CHECK_EQ(oldNinja.getLocation().GetX(), 1);
    CHECK_EQ(oldNinja.getLocation().GetY(), 1);
    oldNinja2.move(&oldNinja);
    CHECK_EQ(oldNinja2.getLocation().GetX(), 1);
    CHECK_EQ(oldNinja2.getLocation().GetY(), 1);

    CHECK_EQ(oldNinja.isAlive(), true);
}

TEST_CASE("Test TrainedNinja") {
    TrainedNinja trainedNinja("Saske",Point(1,1));
    TrainedNinja trainedNinja2("Saske2",Point(0,0));
    CHECK_EQ(trainedNinja.getName(), "Saske");
    CHECK_EQ(trainedNinja.getLocation().GetX(), 1);
    CHECK_EQ(trainedNinja.getLocation().GetY(), 1);
    CHECK_EQ(trainedNinja.isAlive(), true);
    trainedNinja2.move(&trainedNinja);
    CHECK_EQ(trainedNinja2.getLocation().GetX(), 1);
    CHECK_EQ(trainedNinja2.getLocation().GetY(), 1);

}

TEST_CASE("Test YoungNinja class") {
    YoungNinja youngNinja("Deco", Point(1,1));
    CHECK_EQ(youngNinja.getName(), "Deco");
    CHECK_EQ(youngNinja.getLocation().GetX(), 1);
    CHECK_EQ(youngNinja.getLocation().GetY(), 1);
    CHECK_EQ(youngNinja.isAlive(), true);
}

TEST_CASE("Test Team class") {
    Cowboy cowboy("Cowboy1", Point(0,0));
    Team team1(&cowboy);
    CHECK_EQ(team1.stillAlive(), 1);

    SUBCASE("add") {
        Cowboy *cowboy2 = new Cowboy("cowboy2", Point(1, 1));
        CHECK_NOTHROW(team1.add(cowboy2));
        CHECK_EQ(team1.stillAlive(), 2);
    }

    SUBCASE("Test attack") {
        Cowboy anamy("ben", Point(2, 2));
        Team team2(&anamy);
        CHECK_NOTHROW(team1.attack(&team2));
        team1.attack(&team2);
        team1.attack(&team2);
        team1.attack(&team2);
        team1.attack(&team2);
        team1.attack(&team2);
        team1.attack(&team2);

        // CHECK_EQ(team2.stillAlive(), 0);
    }
}

TEST_CASE("Test Team2 class") {
    Character character(Point(1,1), 20, "Naor");
    CHECK_NOTHROW(Team2 team1(&character));
    }

TEST_CASE("Test SmartTeam class") {
    Character character(Point(1,1), 20, "Naor");
    CHECK_NOTHROW(SmartTeam team1(&character));

}

TEST_CASE("Test Cowboy reload") {
    Cowboy cowboy("Cowboy1", Point(1,1));
    CHECK_NOTHROW(cowboy.shoot(&cowboy));
    cowboy.shoot(&cowboy);
    cowboy.shoot(&cowboy);
    cowboy.shoot(&cowboy);
    cowboy.shoot(&cowboy);
    cowboy.shoot(&cowboy);
    CHECK_EQ(cowboy.hasboolets(), false);
    CHECK_NOTHROW(cowboy.reload());
    CHECK(cowboy.hasboolets());
}


TEST_CASE("Test ninja slashing") {
    Point p1(0, 0);
    Point p2(1, 1);
    OldNinja ninja("Naruto", p1);
    Cowboy cowboy("Saske", p2);
    CHECK_NOTHROW(ninja.slash(&cowboy));
    ninja.slash(&cowboy);
    ninja.slash(&cowboy);
    ninja.slash(&cowboy);
    CHECK_EQ(cowboy.isAlive(), false); // Assuming one slash is enough to defeat a character
}


TEST_CASE("Test team with multiple kind") {
    Point p1(0, 0);
    Point p2(1, 1);
    Cowboy cowboy("otis", p1);
    OldNinja ninja("narotu", p2);
    Team team1(&cowboy);
    team1.add(&ninja);
    CHECK_EQ(team1.stillAlive(), 2);
}

TEST_CASE("Test character hit points") {
    Character character(Point(1,1), 20, "Naor");
    CHECK(character.isAlive());
    character.hit(10);
    CHECK(character.isAlive());
    character.hit(10);
    CHECK_FALSE(character.isAlive());
}

   