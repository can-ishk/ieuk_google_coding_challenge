#pragma once

#include <string>
#include <vector>
#include "video.h"
#include <iostream>
#include "videolibrary.h"
#include <ctype.h>
/** A class used to represent a Playlist */

class VideoPlaylist {
private:
	std::string PlaylistId;
	std::vector<std::string> list;
	

public:
	std::vector<std::string> getPlaylist();
	std::string getPlaylistId();
	void playlistId(std::string);
	void addVideo(std::string);
	bool checkPlaylist(std::string);
	void deleteFromPlaylist(std::string);
	friend bool operator==(const VideoPlaylist& id1, const std::string & id2) {
		//return id1.PlaylistId.compare(id2); 
		if (strcmpi(id1.PlaylistId.c_str(), id2.c_str()) == 0) return true;
		else return false;
	}
	void clearPlaylist();
	
};
