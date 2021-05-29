#include "Tickets.h"


Show* Tickets ::findShow(const String& showName, const Date& date) {
	for (size_t i = 0; i < shows.getSize(); i++)
	{
		if (shows[i].getShowName() == showName && shows[i].getDate() == date) {
			return &(shows[i]);
		}

	}
	return nullptr;
}

void Tickets:: addEvent() {
	Date date;
	int hallNumber;
	String showName;

	std::cin >> date >> hallNumber >> showName;

	if (halls[hallNumber].isBooked(date)) {
		std::cout << " This hall is not available" << std::endl;
	}
	else {
		int numberOfRows = halls[hallNumber].getNumberRows();
		int numberOfColumns = halls[hallNumber].getNumberColumns();
		Show newShow(showName, numberOfRows, numberOfColumns, date);
		shows.pushBack(newShow);
		halls[hallNumber].book(date);

	}
}

void Tickets:: freeSeats() {
	String showName;
	Date date;

	std::cin >> showName >> date;

	Show* foundShow = findShow(showName, date);

	if (foundShow != nullptr) {
		std::cout << foundShow->getFreeSeats() << std::endl;
	}
	else {
		std::cout << "This event is not found" << std::endl;
	}
}

void Tickets::book() {
	int rowNumber;
	int seatNumber;
	Date date;
	String showName;
	String receipt;

	std::cin >> rowNumber >> seatNumber >> date >> showName >> receipt;

	Show* foundShow = findShow(showName, date);

	if (foundShow != nullptr) {
		if (foundShow->isValid(rowNumber, seatNumber) && !foundShow->isBooked(rowNumber, seatNumber)) {
			foundShow->bookSeat(rowNumber, seatNumber, receipt);
		}
		else {
			std::cout << " This seat is not available or already booked" << std::endl;
		}
	}
	else {
		std::cout << "This event is not found" << std::endl;
	}
}

void Tickets::unbook() {
	int rowNumber;
	int seatNumber;
	Date date;
	String showName;

	std::cin >> rowNumber >> seatNumber >> date >> showName;
	Show* foundShow = findShow(showName, date);

	if (foundShow != nullptr) {
		if (foundShow->isValid(rowNumber, seatNumber) && foundShow->isBooked(rowNumber, seatNumber)) {
			foundShow->unbookSeat(rowNumber, seatNumber);
		}
		else {
			std::cout << " This seat is not available or not booked" << std::endl;
		}
	}
	else {
		std::cout << "This event is not found" << std::endl;
	}

}

void Tickets:: buy() {
	int rowNumber;
	int seatNumber;
	Date date;
	String showName;

	std::cin >> rowNumber >> seatNumber >> date >> showName;

	Show* foundShow = findShow(showName, date);

	if (foundShow != nullptr) {
		if (foundShow->isValid(rowNumber, seatNumber) && !foundShow->isPurchased(rowNumber, seatNumber)) {
			foundShow->purchaseTicket(rowNumber, seatNumber);
		}
		else {
			std::cout << "Seat not available or already bought, choose another seat." << std::endl;
		}
	}
	else {
		std::cout << "This event is not  found" << std::endl;
	}
}

void Tickets:: check() {
	int serialNumber;
	std::cin >> serialNumber;
	for (size_t i = 0; i < shows.getSize(); i++)
	{
		int seatNumber = shows[i].getSeatNumber(serialNumber);
		if (seatNumber != -1) {
			std::cout << "Valid ticket with seat: " << seatNumber << std::endl;
		}
		else {
			std::cout << "Invalid ticket" << std::endl;
		}
	}
}

/*void Tickets:: report() {
		Date dateFrom;
		Date dateTo;
		std::cin >> dateFrom >> dateTo;

		int hallNumber;
		bool isHallRead = false;

		if (std::cin.peek() != '\n') {
			std::cin >> hallNumber;
			isHallRead = true;
		}
		for (int i = 0; i < shows.getSize(); i++)
		{
			if (!isHallRead || shows[i].getHallNumber() == hallNumber) {
				std::cout << shows[i].getShowName() << ", " << shows[i].getDate()<< ": "
					<< shows[i].getPurchasedSeatsInDateInterval(dateFrom,dateTo) << std::endl;
			}
		}
	}*/

void Tickets::run() {
	std::cout << "Please enter all dates in the format : YYYY-MM-DD" << std::endl;

	String command;

	while (true) {
		std::cin >> command;

		if (command == "addevent") {
			addEvent();
		}
		else if (command == "freeseats") {
			freeSeats();
		}
		else if (command == "book") {
			book();
		}
		else if (command == "unbook") {
			unbook();
		}
		else if (command == "buy") {
			buy();
		}
		/*else if (command == "bookings") {
			bookings();
		}*/
		else if (command == "check") {
			check();
		}
		/*else if (command == "report") {
			report();
		}*/
	}
}