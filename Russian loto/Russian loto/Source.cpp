#include <iostream>

int lottery(int& tickets) {
	int ver_jeckpot = rand() % 100 + 1; // вероятность выигрыша
	
	if (ver_jeckpot <= 1) {
		std::cout << "ДЖЕКПОТ: 200 000 рублей и 10 билетов \"Русское лото\"!!!!" << "\n";
		tickets--; // используем 1 билет
		return 200000; // возвращаем сумму джекпота
		tickets += 10; // если джекпот выигран то к кол-ву билетов +10
	}
	if (ver_jeckpot <= 49) {
		tickets--; // возвращаем сумму выигрыша
		return rand() % 500; // возвращаем сумму выигрыша
	}
	else {
		tickets--; // возвращаем сумму выигрыша
		return 0; // если нет выигрыша
	}
}

int main() {
	setlocale(LC_ALL, "RU");

	int tickets = 10; // кол-во билетов
	int sumWin = 0; // суммарный выигрыш

	while(tickets > 0)
	{
		int win = lottery(tickets); // выигрыш за один билет
		sumWin += win; // прибавляем выигрыш с одного билета к общей сумме

		std::cout << "Вы выиграли: " << win << " рублей" << std::endl;
		std::cout << "Осталось билетов: " << tickets << "\n" << "\n";
	}
	std::cout << "Сумма выигрыша: " << sumWin << " рублей" << std::endl;
	std::cout << "Нажмите любую клавишу и Shift чтобы закрыть это окно";
	std::cin >> sumWin;

	return 0;
}