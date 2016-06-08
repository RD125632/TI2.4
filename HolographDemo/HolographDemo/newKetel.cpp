#include "NewKetel.h"

NewKetel::NewKetel(std::string path, float x, float y, float z) : Object(x, y, z, path)
{
}

NewKetel::NewKetel(std::string path, Vec3f* location) : Object(location, path)
{
}

NewKetel::~NewKetel()
{
}
