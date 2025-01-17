/*
	Copyright 2020 Limeoats
	Original project: https://github.com/Limeoats/L2DFileDialog

	Changes by Vladimir Sigalkin
*/

#pragma once
#include <time.h>
#include <algorithm>
#include <cstring>
#include <chrono>
#include <string>
#include <sstream>
#include <vector>
#include <imgui.h>

#include <filesystem>
#include <imgui.h>

typedef int ImGuiFileDialogType;	// -> enum ImGuiFileDialogType_        // Enum: A file dialog type

enum ImGuiFileDialogType_
{
	ImGuiFileDialogType_OpenFile,
	ImGuiFileDialogType_SaveFile,
	ImGuiFileDialogType_COUNT
};

struct ImFileDialogInfo
{
	std::string title;
	ImGuiFileDialogType type;

	std::filesystem::path fileName;
	std::filesystem::path directoryPath;
	std::filesystem::path resultPath;

    std::string includeFilter;
    std::string excludeFilter;

	bool refreshInfo;
	size_t currentIndex;
	std::vector<std::filesystem::directory_entry> currentFiles;
	std::vector<std::filesystem::directory_entry> currentDirectories;
};

namespace ImGui
{
	IMGUI_API bool FileDialog(bool* open, ImFileDialogInfo* dialogInfo);
}