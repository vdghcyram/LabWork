#pragma once
#include <unordered_map>
#include "tube.h"
#include "cs.h"

void LoadAll(unordered_map<int, tube>& GroupTube, unordered_map<int, cs>& GroupCS);
void SaveAll(const unordered_map<int, tube>& GroupTube, const unordered_map<int, cs>& GroupCS);