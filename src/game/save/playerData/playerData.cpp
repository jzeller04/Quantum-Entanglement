#include "save/playerData/playerData.hpp"

void qe::loadPlayerData(PlayerData &playerData)
{
    Stats playerStats;
    ProgressInfo playerProgress;
    PlayerData newplayerData;
}
void qe::savePlayerData(PlayerData &playerData)
{
    json j;
    j = playerData;
    std::cout << j << std::endl;
    std::ofstream file("./data/saves/" + playerData.saveName + ".json");
    if(file.is_open())
    {
        file << j.dump(4);
        file.close();
    }
    else
    {
        std::cerr << "Error opening save file..." << std::endl;
    }

}
void qe::to_json(json &j, const PlayerData &playerdata)
{
    j = json{ {"save", playerdata.saveName}, {"created", playerdata.timeCreated}, {"lastplayed", playerdata.lastPlayed}, 
    {"progressinfo",{ 
        {"energy", playerdata.progress.energy}, 
        {"networth", playerdata.progress.worth},
        {"threshholds", playerdata.progress.threshholds}}},
    {"playerstats",{
        {"speed", playerdata.playerStats.speed},
        {"size", playerdata.playerStats.size}
    }}};
}

void qe::from_json(json &j, PlayerData &playerdata)
{

}