class Point {
private:
	int number;
	vector<Pair<Point,int>> linkedToPoints;//points where it is possible to go from the current point.A->B B is possible from A
	vector<Pair<Point,int>> linkedFromPoints;//points where path the current point exists. A->B. A is possible for B
	void connectFrom(Point fromPnt, int distance) {
		linkedFromPoints.append(Pair<Point, int>(fromPnt, distance));
	}//only called within connect(). never call on its own
public:
	Point(int numberInput) {
		number = numberInput;
	}
	void connect(Point newPnt, int distance) {
		linkedToPoints.append(Pair<Point, int>(newPnt, distance));
		newPnt.connectFrom(newPnt, distance);
	}
};

class gameMap {
public:
	gameMap() {//default mode. 

	}
	gameMap(String filePath) {//read txt file. tbd
		
	}
};