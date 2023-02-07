#include <string>
#include <array>

static const std::string SPRITE_SHEET = "Resources\\SpriteSheet.png";
static const int HOR_TILE_COUNT = 20;
static const int VERT_TILE_COUNT = 20;
static const int TILE_SIZE = 15;
static const int MINE_CHANCE = 15;

static std::array<const int, 2> UNCHECKED_POS = { 14, 195 };
static std::array<const int, 2> MINE_POS = { 99, 195 };
static std::array<const int, 2> EMPTY_POS = { 31, 195 };
static std::array<const int, 2> ONE_POS = { 14, 212 };
static std::array<const int, 2> TWO_POS = { 31, 212 };
static std::array<const int, 2> THREE_POS = { 48, 212 };
static std::array<const int, 2> FOUR_POS = { 65, 212 };
static std::array<const int, 2> FIVE_POS = { 82, 212 };
static std::array<const int, 2> SIX_POS = { 99, 212 };
static std::array<const int, 2> SEVEN_POS = { 116, 212 };
static std::array<const int, 2> EIGHT_POS = { 133, 212 };