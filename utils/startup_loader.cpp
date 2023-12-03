#include "./startup_loader.hpp"
#include "../shared/color_constants.hpp"
#include "../shared/character_constants.hpp"

const int kSpinnerSize = 12;

void ClearScreenForReRender() { std::cout << "\033[2J\033[1;1H"; }

void DisplaySpinner(char spinner[kSpinnerSize][kSpinnerSize], int phase)
{
  for (int i = 0; i < kSpinnerSize; ++i)
  {
    for (int j = 0; j < kSpinnerSize; ++j)
    {
      if (spinner[i][j] == kSpinnerChar)
      {
        std::cout << kRedColor << spinner[i][j] << ' ' << kResetColor;
      }
      else
      {
        std::cout << kBlueColor << spinner[i][j] << ' ' << kResetColor;
      }
    }
    std::cout << std::endl;
  }
}

void UpdateSpinner(char spinner[kSpinnerSize][kSpinnerSize], int &phase)
{
  int radius = kSpinnerSize / 2 - 1;
  int center_x = kSpinnerSize / 2, center_y = kSpinnerSize / 2;

  // Initialize spinner with spaces
  for (int i = 0; i < kSpinnerSize; ++i)
  {
    for (int j = 0; j < kSpinnerSize; ++j)
    {
      spinner[i][j] = ' ';
    }
  }

  // Draw the static circle
  for (double angle = 0; angle < 360; angle += 0.5)
  {
    int x = center_x + static_cast<int>(radius * cos(angle * M_PI / 180));
    int y = center_y + static_cast<int>(radius * sin(angle * M_PI / 180));
    if (x >= 0 && x < kSpinnerSize && y >= 0 && y < kSpinnerSize)
    {
      spinner[x][y] = kSpinnerBackgroundChar;
    }
  }

  // Highlight a segment of the circle
  for (double angle = phase; angle < phase + 60; angle += 0.5)
  { // 60-degree segment
    int x = center_x + static_cast<int>(radius * cos(angle * M_PI / 180));
    int y = center_y + static_cast<int>(radius * sin(angle * M_PI / 180));
    if (x >= 0 && x < kSpinnerSize && y >= 0 && y < kSpinnerSize)
    {
      spinner[x][y] = kSpinnerChar;
    }
  }

  // Update phase for rotation
  phase = (phase + 5) % 360;
}

void RunSpinner()
{
  char spinner[kSpinnerSize][kSpinnerSize];
  int phase = 0;

  auto start = std::chrono::steady_clock::now();
  auto end = start;

  while (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() < 10000)
  {
    UpdateSpinner(spinner, phase);
    DisplaySpinner(spinner, phase);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    ClearScreenForReRender();
    end = std::chrono::steady_clock::now();
  }
}

void StartUpLoader()
{
  std::thread loading_thread(RunSpinner);
  loading_thread.join();
}
