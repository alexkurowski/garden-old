using std::cout;
using std::endl;
using std::get;
using std::string;
using std::to_string;
using std::variant;
using std::vector;

using cstring = const char *;
using EntityId = unsigned int;
using ComponentMask = unsigned long long int;

constexpr EntityId ENTITY_POOL = 5;