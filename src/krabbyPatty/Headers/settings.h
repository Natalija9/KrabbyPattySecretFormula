#ifndef SETTINGS_H
#define SETTINGS_H

enum class Mode { EasyMode = 0, HardMode = 1 };

class Settings {
public:
  Settings();

  void setSound(int isSoundOn);
  void setMode(Mode mode);
  bool getSound();
  Mode getMode();
  ~Settings();

private:
  bool _sound;
  Mode _mode;
};

#endif // SETTINGS_H
