#include "videoplayer.h"
#include "videoplayer.h"
#include "videoplayer.h"
#include "videoplayer.h"
#include <string>
#include <iostream>
#include <algorithm>


std::string VideoPlayer::currentlyPlaying() {
    return currentlyPlayingId;
}

void VideoPlayer::currentlyPlaying(std::string videoId) {
    currentlyPlayingId = videoId;
}
std::string VideoPlayer::currentState()
{
    return state;
}

void VideoPlayer::currentState(std::string cstate)
{
    state = cstate;
}

void VideoPlayer::numberOfVideos() {
  std::cout << mVideoLibrary.getVideos().size() << " videos in the library"
            << std::endl;
}
bool mycomp(Video a, Video b) {
    return a.getTitle() < b.getTitle();
}
void VideoPlayer::showAllVideos() {
  //std::cout << "showAllVideos needs implementation" << std::endl;
    std::cout << "Here's a list of all available videos:\n";
    size_t numberOfVideos = mVideoLibrary.getVideos().size();
    std::vector<Video> allVideos = mVideoLibrary.getVideos();
    std::sort(allVideos.begin(), allVideos.end(), mycomp);
    for (int i = 0; i < numberOfVideos; i++) {
        std::cout << allVideos[i].getTitle() << " (" << allVideos[i].getVideoId() << ") [";
        for (auto j : allVideos[i].getTags())
            if (j.compare(allVideos[i].getTags().back())==0) std::cout <<j;
            else std::cout << j << ' ';
           std::cout << "]\n";
    }
}

void VideoPlayer::playVideo(const std::string& videoId) {
  //std::cout << "playVideo needs implementation" << std::endl;
    if (currentlyPlaying() == "null") {
        if (mVideoLibrary.getVideo(videoId)) {
            currentlyPlaying(videoId);
            std::cout << "Playing video: " << mVideoLibrary.getVideo(currentlyPlaying())->getTitle() << std::endl;
            currentState("playing");
        }
        else  std::cout << "Cannot play video: Video does not exist\n";
    }
    else {
        if (mVideoLibrary.getVideo(videoId)) {

            std::cout << "Stopping video: " << mVideoLibrary.getVideo(currentlyPlaying())->getTitle()<<"\n";
            currentlyPlaying(videoId);
            std::cout << "Playing video: " << mVideoLibrary.getVideo(currentlyPlaying())->getTitle()<<"\n";
            currentState("playing");
        }
        else {
            std::cout << "Cannot play video: Video does not exist\n";
        }
    }
}

void VideoPlayer::stopVideo() {
  //std::cout << "stopVideo needs implementation" << std::endl;
    if (currentlyPlaying() == "null") {
        std::cout << "Cannot stop video: No video is currently playing\n";
    }
    else {
        std::cout << "Stopping video: " << mVideoLibrary.getVideo(currentlyPlaying())->getTitle()<<std::endl;
        currentlyPlaying("null");
        currentState("null");
    }
}

void VideoPlayer::playRandomVideo() {
    //std::cout << "playRandomVideo needs implementation" << std::endl;
        playVideo(mVideoLibrary.getVideos()[std::rand() % (mVideoLibrary.getVideos().size())].getVideoId());
       // std::cout << "Playing video:" << mVideoLibrary.getVideo(currentlyPlaying())->getTitle()<<"\n";       
}

void VideoPlayer::pauseVideo() {
  //std::cout << "pauseVideo needs implementation" << std::endl;
    if (currentState() == "playing") {
        std::cout << "Pausing video: " << mVideoLibrary.getVideo(currentlyPlaying())->getTitle() << std::endl;
        currentState("paused");
    }
    else if (currentState() == "paused") {
        std::cout << "Video already paused: " << mVideoLibrary.getVideo(currentlyPlaying())->getTitle() << std::endl;
    }
    else if (currentState() == "null") {
        std::cout << "Cannot pause video: No video is currently playing" << std::endl;
    }
}

void VideoPlayer::continueVideo() {
  //std::cout << "continueVideo needs implementation" << std::endl;
    if (currentState() == "paused") {
        std::cout << "Continuing video: " << mVideoLibrary.getVideo(currentlyPlaying())->getTitle() << std::endl;
        currentState("playing");
    }
    else if (currentState() == "playing") {
        std::cout << "Cannot continue video: Video is not paused\n";
    }
    else if (currentState() == "null") {
        std::cout << "Cannot continue video: No video is currently playing" << std::endl;
    }
}

void VideoPlayer::showPlaying() {
  //std::cout << "showPlaying needs implementation" << std::endl;
    if (currentlyPlaying() == "null") {
        std::cout << "No video is currently playing\n";
    }
    else {
        std::cout << "Currently playing: " << mVideoLibrary.getVideo(currentlyPlaying())->getTitle() << " (" << mVideoLibrary.getVideo(currentlyPlaying())->getVideoId() << ") [";
        for (auto j : mVideoLibrary.getVideo(currentlyPlaying())->getTags())
            if (j.compare(mVideoLibrary.getVideo(currentlyPlaying())->getTags().back()) == 0) std::cout << j;
            else std::cout << j << ' ';
        std::cout << "]";
        if (currentState() == "paused") std::cout << " - PAUSED\n";
        else std::cout << std::endl;
    }
}

void VideoPlayer::createPlaylist(const std::string& playlistName) {
  //std::cout << "createPlaylist needs implementation" << std::endl;
    auto pl = std::find(Playlist.begin(), Playlist.end(), playlistName);
    __int64 index = pl - Playlist.begin();
    if (index>=Playlist.size()||Playlist.empty()) {
        VideoPlaylist play;
        play.playlistId(playlistName);
        Playlist.push_back(play);
        std::cout << "Successfully created new playlist: " << playlistName << std::endl;
    }
    else std::cout << "Cannot create playlist: A playlist with the same name already exists\n";
    
}

void VideoPlayer::addVideoToPlaylist(const std::string& playlistName,
                                     const std::string& videoId) {
 // std::cout << "addVideoToPlaylist needs implementation" << std::endl;
    auto pl = std::find(Playlist.begin(), Playlist.end(), playlistName);
    __int64 index = std::distance(pl, Playlist.begin());
    if (pl != Playlist.end()) {
        if (mVideoLibrary.getVideo(videoId)) {
           
            
            if (Playlist[index].checkPlaylist(videoId)==false) {
                
                Playlist[index].addVideo(videoId);
                std::cout << "Added video to " << playlistName << ": " << mVideoLibrary.getVideo(videoId)->getTitle() << "\n";

            }
            else
                std::cout << "Cannot add video to " << playlistName << ": Video already added\n";
        }
        else
            std::cout << "Cannot add video to " << playlistName << ": Video does not exist\n";

    }
    else {
        std::cout << "Cannot add video to " << playlistName << ": Playlist does not exist\n";
    }

}
bool mycomp1(std::string a, std::string b) {
    return a < b;
}
void VideoPlayer::showAllPlaylists() {
  //std::cout << "showAllPlaylists needs implementation" << std::endl;
    if (Playlist.empty()) std::cout << "No playlists exist yet\n";
    else {
        std::cout << "Showing all playlists:";
        std::vector<std::string> allPlaylists;
        
        for (auto i : Playlist) {
            //std::cout << "\n"<< i.getPlaylistId();
            allPlaylists.push_back(i.getPlaylistId());
        }
       std::sort(allPlaylists.begin(), allPlaylists.end(), mycomp1);
        for (auto i : allPlaylists) {
            std::cout << "\n" << i;
        }
        std::cout << std::endl;

    }
}

void VideoPlayer::showPlaylist(const std::string& playlistName) {
  //std::cout << "showPlaylist needs implementation" << std::endl;
    auto pl = std::find(Playlist.begin(), Playlist.end(), playlistName);
    if (pl != Playlist.end()) {
        __int64 index = pl - Playlist.begin();
        std::cout << "Showing playlist: " << Playlist[index].getPlaylistId() << std::endl;
        if (Playlist[index].getPlaylist().empty()) std::cout << "No videos here yet\n";
        else {
            for (auto k : Playlist[index].getPlaylist()) {
                std::cout << mVideoLibrary.getVideo(k)->getTitle() << " (" << mVideoLibrary.getVideo(k)->getVideoId() << ") [";
                for (auto j : mVideoLibrary.getVideo(k)->getTags())
                    if (j.compare(mVideoLibrary.getVideo(k)->getTags().back()) == 0) std::cout << j;
                    else std::cout << j << ' ';
                std::cout << "]\n";
            }
        }
    }
    else {
        std::cout << "Cannot show playlist " << playlistName << ": Playlist does not exist\n";

    }
}

void VideoPlayer::removeFromPlaylist(const std::string& playlistName,
                                     const std::string& videoId) {
  //std::cout << "removeFromPlaylist needs implementation" << std::endl;
    auto pl = std::find(Playlist.begin(), Playlist.end(), playlistName);
    if (pl != Playlist.end()) {
        __int64 index = pl - Playlist.begin();
        if (mVideoLibrary.getVideo(videoId)) {

            if (Playlist[index].checkPlaylist(videoId) ==false) std::cout << "Cannot remove video from " << playlistName << ": Video is not in playlist\n";
            else {
                Playlist[index].deleteFromPlaylist(videoId);
                std::cout << "Removed video from " << playlistName << ": " << mVideoLibrary.getVideo(videoId)->getTitle() << std::endl;

            }
        }
        else {
            std::cout << "Cannot remove video from " << playlistName << ": Video does not exist\n";

        }
    }
    else {
        std::cout << "Cannot remove video from " << playlistName << ": Playlist does not exist\n";

    }
}

void VideoPlayer::clearPlaylist(const std::string& playlistName) {
  //std::cout << "clearPlaylist needs implementation" << std::endl;
    auto pl = std::find(Playlist.begin(), Playlist.end(), playlistName);
    if (pl != Playlist.end()) {
        
        std::cout << "Successfully removed all videos from: " << playlistName << std::endl;
        Playlist[pl - Playlist.begin()].clearPlaylist();

    }
    else {
        std::cout << "Cannot clear playlist " << playlistName << ": Playlist does not exist\n";

    }
}

void VideoPlayer::deletePlaylist(const std::string& playlistName) {
  //std::cout << "deletePlaylist needs implementation" << std::endl;
  auto pl = std::find(Playlist.begin(), Playlist.end(), playlistName);
  if (pl != Playlist.end()) {
      std::cout << "Deleted playlist: " << playlistName << std::endl;
      Playlist.erase(pl);
  }
  else {
      std::cout << "Cannot delete playlist " << playlistName << ": Playlist does not exist\n";
  }
}

void VideoPlayer::searchVideos(const std::string& searchTerm) {
  std::cout << "searchVideos needs implementation" << std::endl;
}

void VideoPlayer::searchVideosWithTag(const std::string& videoTag) {
  std::cout << "searchVideosWithTag needs implementation" << std::endl;
}

void VideoPlayer::flagVideo(const std::string& videoId) {
  std::cout << "flagVideo needs implementation" << std::endl;
}

void VideoPlayer::flagVideo(const std::string& videoId, const std::string& reason) {
  std::cout << "flagVideo needs implementation" << std::endl;
}

void VideoPlayer::allowVideo(const std::string& videoId) {
  std::cout << "allowVideo needs implementation" << std::endl;
}
