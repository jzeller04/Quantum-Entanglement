#pragma once
#include <string>
#include <vector> // maybe not use vector later when we know the exact amount of thresholds
#include <json.hpp>
#include <iostream>
#include <fstream>
using json = nlohmann::json;





namespace qe
{

    enum class Threshholds
    {
        START
    };

    struct Stats
    {
        float speed;
        float size;
    };

    struct ProgressInfo
    {
        long energy;
        long worth;
        std::vector<Threshholds> threshholds;
    };

    struct PlayerData
    {
        std::string saveName;
        std::string timeCreated;
        std::string lastPlayed;

        ProgressInfo progress;
        Stats playerStats;
    };

    void loadPlayerData(PlayerData &playerData);

    void savePlayerData(PlayerData &playerData);

    void to_json(json& j, const PlayerData &playerdata);
    void from_json(json& j, PlayerData &playerdata);
    
};