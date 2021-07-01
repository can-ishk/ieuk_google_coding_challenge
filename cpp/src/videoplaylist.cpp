#include "videoplaylist.h"
#include <iostream>

std::vector<std::string> VideoPlaylist::getPlaylist() {
	return list;
}

std::string VideoPlaylist::getPlaylistId() {
	return PlaylistId;
}

void VideoPlaylist::playlistId(std::string Id) {
	PlaylistId = Id;
}

void VideoPlaylist::addVideo(std::string Id) {
	list.push_back(Id);
}

bool VideoPlaylist::checkPlaylist(std::string id)
{
	auto it = std::find((list).begin(), (list).end(), id);
	if (it != list.end()) return true;
	else return false;
}

void VideoPlaylist::deleteFromPlaylist(std::string id) {

	auto it = std::find(list.begin(), list.end(), id);
	list.erase(it);
}

void VideoPlaylist::clearPlaylist() {
	list.clear();
}





