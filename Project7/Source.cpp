#include <iostream>  
#include <cstdlib>  // Для rand() и srand()  
#include <ctime>    // Для time()  
using namespace std;
const string symbols[] = { "Вишня", "Лимон", "Апельсин", "Арбуз", "Звонок", "Звезда", "Деньги" }; // Символы на барабанах  

void spinReels(string& reel1, string& reel2, string& reel3) {
    reel1 = symbols[rand() % 7];
    reel2 = symbols[rand() % 7];
    reel3 = symbols[rand() % 7];
}

bool checkWin(const string& reel1, const string& reel2, const string& reel3) {
    return (reel1 == reel2 && reel2 == reel3); // Все три барабана должны совпадать  
}

int main() {
    setlocale(LC_ALL,"Russian");
    srand(static_cast<unsigned int>(time(0))); 

    cout << "Добро пожаловать в игру 'Однорукий бандит'!" << endl;
    cout << "Нажмите Enter, чтобы начать..." << endl;

    while (true) {
        cin.get(); // Дождаться нажатия Enter  

        string reel1, reel2, reel3;
        spinReels(reel1, reel2, reel3); // Крутить барабаны  

        // Показ символов в барабанах  
        cout << "🎰 " << reel1 << " | " << reel2 << " | " << reel3 << " 🎰" << endl;

        // Проверка на выигрыш  
        if (checkWin(reel1, reel2, reel3)) {
            cout << "Поздравляем! Вы выиграли!" << endl;
        }
        else {
            cout << "К сожалению, вы ничего не выиграли. Попробуйте снова!" << endl;
        }

        cout << "Нажмите 'q', чтобы выйти или Enter, чтобы продолжить..." << endl;
        char choice = cin.get();
        if (choice == 'q' || choice == 'Q') {
            break; // Выйти из игры  
        }
        cin.ignore(); // Игнорирование символа новой строки после ввода  
    }

   cout << "Спасибо за игру! До свидания!" << endl;
    return 0;
}