#include <string>
#include <vector> // maybe not use vector later when we know the exact amount of thresholds

enum class Threshholds
{

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

struct playerData
{
    std::string saveName;
    std::string timeCreated;
    std::string lastPlayed;

    ProgressInfo progress;
    Stats playerStats;
};