#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

enum eCommands {
	PLAY = 1,
	PAUSE,
	NEXT,
	STOP,
	EXIT
};

class Track
{
private:
	std::string m_trackName;
	std::tm m_timeInit;
	int m_duration;

public:
	std::string getName() { return m_trackName; }

	void setName(std::string& name) { m_trackName = name; }
	void setTime(std::tm& time) { m_timeInit = time; }
	void setDuration(int& duration) { m_duration = duration; }
};

class AudioPlayer
{
private:
	std::vector<Track> m_songs;
	bool isPause = false;
	bool isPlaying = false;

public:
	void addNewSong(std::string name, std::tm& time, int duration) {
		Track* temp = new Track;

		temp->setName(name);
		temp->setTime(time);
		temp->setDuration(duration);

		m_songs.push_back(*temp);

		delete temp;
		temp = nullptr;
	}

	void playSong() {
		if (isPause) {
			isPlaying = true;
			isPause = false;

			std::cout << "-------------Continue to play song!--------------" << std::endl;
		}
		else if (!isPlaying) {
			std::cout << "--------------SONGS---------------" << std::endl;

			for (int i = 0; i < m_songs.size(); ++i) {
				std::cout << i + 1 << ". " << m_songs[i].getName() << std::endl;
			}

			std::cout << "Input number of song you wish to play: ";
			int temp;
			std::cin >> temp;

			while (temp < 1 || temp > m_songs.size()) {
				std::cout << "Wrong input! Try again: ";
				std::cin >> temp;
			}

			isPlaying = true;

			std::cout << "\"" << m_songs[--temp].getName() << "\" is now playing." << std::endl;
		}
	}

	void pauseSong() {
		if (isPlaying) {

			isPause = true;
			isPlaying = false;

			std::cout << "Song PAUSED" << std::endl;
		}
		else std::cout << "Song is already in pause!" << std::endl;
	}

	void nextSong() {
		isPause = false;
		isPlaying = true;

		std::srand(std::time(nullptr));

		int temp = std::rand() % m_songs.size();

		std::cout << "\"" << m_songs[temp].getName() << "\" is now playing." << std::endl;
	}
};

void showMenu() {
	std::cout << PLAY << ". play song you want or continue paused song;" << std::endl;
	std::cout << PAUSE << ". pause song;" << std::endl;
	std::cout << NEXT << ". next song;" << std::endl;
	std::cout << STOP << ". stop playing song;" << std::endl;
	std::cout << EXIT << ". exit programm." << std::endl;

	std::cout << "Input number of command you wish to do: ";
}

void initSomeSongs(AudioPlayer& audio) {

	std::time_t start = std::time(nullptr);
	std::tm time = *std::localtime(&start);

	audio.addNewSong("Metallica", time, 600);
	audio.addNewSong("AC/DC", time, 300);
	audio.addNewSong("Judas Priest", time, 800);
	audio.addNewSong("RHCP", time, 400);
	audio.addNewSong("Sex Pistols", time, 200);
}

int main() {

	int userInput;

	AudioPlayer player;

	initSomeSongs(player);

	std::cout << "================WELCOME BACK!===================" << std::endl;

	do {
		showMenu();
		std::cin >> userInput;

		switch (userInput)
		{
		case PLAY:
			system("cls");
			player.playSong();
			break;

		case PAUSE:
			system("cls");
			player.pauseSong();
			break;

		case NEXT:
			system("cls");
			player.nextSong();
			break;

		case EXIT:
			break;

		default:
			std::cout << "Wrong input! Try again!" << std::endl;

			break;
		}
	} while (userInput != EXIT);

	std::cout << "===============GOODBYE=================" << std::endl;
}