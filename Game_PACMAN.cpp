#include<sfml/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class Pinky;
class Pacman {
private:
	Pinky *p1;
	CircleShape AsifPac;
	CircleShape bubbles[20][20];
	RectangleShape borders[30];
	unsigned char direction;
	float pacSpeed;
	float botpacSpeed;
public:

	Pacman() {
	}
	void setScreen(Vector2u size) {
		borders[1].setSize(Vector2f(660, 5));
		borders[1].setPosition(Vector2f(20.f, 20.f));
		borders[2].setSize(Vector2f(660, 5));
		borders[2].setPosition(Vector2f(20.f, 380.f));
		borders[3].setSize(Vector2f(5, 120));
		borders[3].setPosition(Vector2f(680.f, 20.f));
		borders[4].setSize(Vector2f(5, 120));
		borders[4].setPosition(Vector2f(20.f, 20.f));
		borders[5].setSize(Vector2f(5, 120));
		borders[5].setPosition(Vector2f(20.f, 260.f));
		borders[6].setSize(Vector2f(5, 120));
		borders[6].setPosition(Vector2f(680, 261));
		borders[7].setSize(Vector2f(50, 5));
		borders[7].setPosition(Vector2f(20, 140));
		borders[8].setSize(Vector2f(55, 5));
		borders[8].setPosition(Vector2f(630, 140));
		borders[9].setSize(Vector2f(50, 5));
		borders[9].setPosition(Vector2f(20, 260));
		borders[10].setSize(Vector2f(55, 5));
		borders[10].setPosition(Vector2f(630, 260));
		borders[11].setSize(Vector2f(5, 125));
		borders[11].setPosition(Vector2f(70, 140));
		borders[12].setSize(Vector2f(5, 125));
		borders[12].setPosition(Vector2f(630, 140));
		// Ghost home
		borders[13].setSize(Vector2f(150, 5));
		borders[13].setPosition(Vector2f(280, 160));
		borders[14].setSize(Vector2f(150, 5));
		borders[14].setPosition(Vector2f(280, 250));
		borders[15].setSize(Vector2f(5, 90));
		borders[15].setPosition(Vector2f(280, 160));
		borders[16].setSize(Vector2f(5, 95));
		borders[16].setPosition(Vector2f(430, 160));
		//T border
		borders[17].setSize(Vector2f(5, 40));
		borders[17].setPosition(Vector2f(350, 70));
		borders[18].setSize(Vector2f(50, 5));
		borders[18].setPosition(Vector2f(325, 110));
		borders[19].setSize(Vector2f(200, 5));
		borders[19].setPosition(Vector2f(265, 310));
		borders[20].setSize(Vector2f(5, 75));
		borders[20].setPosition(Vector2f(170, 160));
		borders[21].setSize(Vector2f(5, 70));
		borders[21].setPosition(Vector2f(500, 70));
		borders[22].setPosition(Vector2f(140, 160));
		borders[22].setSize(Vector2f(5, 75));
		borders[20].setSize(Vector2f(5, 75));
		borders[20].setPosition(Vector2f(200, 160));
		borders[23].setSize(Vector2f(75, 5));
		borders[23].setPosition(Vector2f(500, 210));

		int x = 0;
		for (int i = 0; i < 18; i++, x += 47) {

			for (int k = 0, j = 18; k < 20; k++, j += 40) {
				bubbles[i][k].setRadius(7.f);
				bubbles[i][k].setPosition(Vector2f((30 + j), (30 + x)));
			}

			cout << endl;

		}
		pacSpeed = 5;
		botpacSpeed = 3;


		AsifPac.setRadius(18.f);
		AsifPac.setPosition(AsifPac.getPosition().x + (size.x - 30) / 2, size.y - 70.f);
	}

	void color() {
		for (int i = 0; i < 30; i++) {
			if (i == 13) {
				borders[i].setFillColor(Color::Magenta);
			}
			else borders[i].setFillColor(Color(50, 50, 250));

		}

		AsifPac.setFillColor(Color(255, 255, 0));
	}

	void draw(RenderWindow* window) {
		CircleShape detector[20][20];
		for (int i = 0; i < 30; i++) {
			window->draw(borders[i]);
		}
		int idx[10]{ 0 }, n = 0, m = 0;

		for (int i = 0; i < 8; i++) {
			for (int k = 0; k < 16; k++) {
				if (bubbles[i][k].getPosition().y > borders[7].getPosition().y && bubbles[i][k].getPosition().y < borders[9].getPosition().y && bubbles[i][k].getPosition().x < borders[11].getPosition().x) {

				}
				else if (bubbles[i][k].getPosition().y > borders[8].getPosition().y && bubbles[i][k].getPosition().y < borders[10].getPosition().y && bubbles[i][k].getPosition().x > borders[12].getPosition().x) {

				}



				else {
					for (int x = 0; x < 23; x++) {
						if (bubbles[i][k].getGlobalBounds().intersects(borders[x].getGlobalBounds())) {
							bubbles[i][k].setPosition(0.f, 0.f);
							bubbles[i][k].setRadius(0.f);
							bubbles[i][k].setFillColor(Color::Black);
							bubbles[1][0].setFillColor(Color::Magenta);
							bubbles[2][9].setFillColor(Color::Magenta);
						}

						else {
							window->draw(bubbles[i][k]);
						}
					}
				}

			}

		}



		window->draw(AsifPac);

	}

	void update() {
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			this->AsifPac.move(pacSpeed, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::A)) {
			this->AsifPac.move(-pacSpeed, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::W)) {
			this->AsifPac.move(0, -pacSpeed);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S)) {
			this->AsifPac.move(0, pacSpeed);
		}
		this->collideObj();
	}

	void collideObj() {
		int j = 0;
		Vector2f playerPos = AsifPac.getPosition();
		for (int i = 0; i < 30; i++) {

			if (AsifPac.getGlobalBounds().intersects(borders[i + 1].getGlobalBounds())) {

				if (i == j) {
					AsifPac.setPosition(AsifPac.getGlobalBounds().left, 28.f);
				}
				else if (i == 2) {
					AsifPac.setPosition(640.f, AsifPac.getGlobalBounds().top);
				}

				else if (i == 1) {
					AsifPac.setPosition(AsifPac.getGlobalBounds().left, 340.f);
				}


				else if (i == 3) {
					AsifPac.setPosition(25.f, AsifPac.getGlobalBounds().top);
				}

				else if (i == 4) {
					AsifPac.setPosition(25.f, AsifPac.getGlobalBounds().top);
				}

				else if (i == 5) {
					AsifPac.setPosition(640.f, AsifPac.getGlobalBounds().top);
				}

				else if (i == 6) {
					AsifPac.setPosition(AsifPac.getGlobalBounds().left, 97.f);
				}

				else if (i == 7) {
					AsifPac.setPosition(AsifPac.getGlobalBounds().left, 97.f);
				}

				else if (i == 8) {
					AsifPac.setPosition(AsifPac.getGlobalBounds().left, 270.f);
				}

				else if (i == 9) {
					AsifPac.setPosition(AsifPac.getGlobalBounds().left, 270.f);
				}

				else if (i == 10) {
					AsifPac.setPosition(79.f, AsifPac.getGlobalBounds().top);
				}

				else if (i == 11) {
					AsifPac.setPosition(590.f, AsifPac.getGlobalBounds().top);
				}
				else if (i == 12) {

					AsifPac.setPosition(AsifPac.getGlobalBounds().left, 120.f);
				}
				else if (i == 13) {

					AsifPac.setPosition(AsifPac.getGlobalBounds().left, 262.f);
				}
				else if (i == 14) {
					AsifPac.setPosition(243.f, AsifPac.getGlobalBounds().top);

				}
				else if (i == 15) {

					AsifPac.setPosition(440.f, AsifPac.getGlobalBounds().top);
				}


			}


		}
		for (int i = 0; i < 8; i++) {
			for (int k = 0; k < 16; k++) {
				if (AsifPac.getGlobalBounds().intersects(bubbles[i][k].getGlobalBounds())) {
					bubbles[i][k].setFillColor(Color::Black);

					if (AsifPac.getGlobalBounds().intersects(bubbles[1][0].getGlobalBounds())) {
						bubbles[i][k].setFillColor(Color::Black);
						pacSpeed = 8;
					}
					if (AsifPac.getGlobalBounds().intersects(bubbles[1][15].getGlobalBounds())) {
						bubbles[i][k].setFillColor(Color::Black);
						pacSpeed = 5;
					}
					if (AsifPac.getGlobalBounds().intersects(bubbles[2][9].getGlobalBounds())) {
						bubbles[i][k].setFillColor(Color::Black);

						pacSpeed = 8;
					}

					if (AsifPac.getGlobalBounds().intersects(bubbles[2][1].getGlobalBounds())) {
						bubbles[i][k].setFillColor(Color::Black);
						pacSpeed = 5;
					}

				}

			}

		}

	}

	RectangleShape* getBorders() {
		return borders;
	}




};


class Ghost {
public:
	virtual void scatter() = 0;
	virtual ~Ghost() {};
};
class Pinky {
	CircleShape Pink;
	unsigned char direction;
	float botpacSpeed;
public:

	Pinky() {
	}
	void setScreen(Vector2u size) {
		int x = 0;
		botpacSpeed = 3;
		Pink.setRadius(18.f);
		Pink.setPosition(Pink.getPosition().x + (size.x - 30) / 2, size.y - 70.f);
	}

	void color() {
		Pink.setFillColor(Color(255, 255, 0));
	}

	void draw(RenderWindow* window) {
		window->draw(Pink);

	}

	void update() {
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			this->Pink.move(botpacSpeed, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::A)) {
			this->Pink.move(-botpacSpeed, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::W)) {
			this->Pink.move(0, -botpacSpeed);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S)) {
			this->Pink.move(0, botpacSpeed);
		}
		this->collideObj();
	}
	Pacman pac;
	void collideObj() {
		int j = 0;
		Vector2f playerPos = Pink.getPosition();

	};

	class Clyde : public Ghost {
		CircleShape Cly;
		float speed;
		void initvars() {
			speed = 0.5;
		}
		void initShape() {
			this->Cly.setRadius(15.f);
			this->Cly.setFillColor(Color::Blue);
			this->Cly.setPosition(Vector2f(300.f, 320.f));
		}
	public:
		Clyde() {
			this->initvars();
			this->initShape();
		}
		void update(RenderWindow* ti) {
			this->scatter();
			this->updatewindowscoll(ti);
		}
		void updatewindowscoll(const RenderWindow* ti) {
			if (this->Cly.getGlobalBounds().left <= 0.f)
				this->Cly.setPosition(0.f, this->Cly.getGlobalBounds().top);
			else  if (this->Cly.getGlobalBounds().left + this->Cly.getGlobalBounds().width >= ti->getSize().x)
				this->Cly.setPosition(ti->getSize().x - this->Cly.getGlobalBounds().width, this->Cly.getGlobalBounds().top);
			if (this->Cly.getGlobalBounds().top <= 0.f)
				this->Cly.setPosition(this->Cly.getGlobalBounds().left, 0.f);
			else  if (this->Cly.getGlobalBounds().top + this->Cly.getGlobalBounds().width >= ti->getSize().x)
				this->Cly.setPosition(this->Cly.getGlobalBounds().left, ti->getSize().x - this->Cly.getGlobalBounds().width);
		}
		void scatter() {
			Cly.move(Vector2f(0, -speed));
			Cly.move(Vector2f(-speed, 0));
		}
		void render(RenderWindow* win) {
			win->draw(Cly);
		}
		virtual ~Clyde() {};
	};

	/*class Ghost {
		CircleShape shape;
		Vector2f size;
		float xPos;
		float yPos;
		Vector2f positions;

	public:
		Ghost() {
			xPos = 1;
			yPos = 1;
			shape.setPosition(30.f,30.f);
			positions = shape.getPosition();

		}

		void size() {
			shape.setRadius((20.f));

		}
		//virtual void color() = 0;




	};

	class Ghost1 {
		CircleShape shape;
		float xPos = 0;
		float yPos = 1;
		Vector2f positions;

	public:



		void color() {
			shape.setFillColor(Color::Red);
		}

		void size() {
			shape.setRadius(20.f);
		}


		void move(Pacman target) {
			positions.x += xPos;
			positions.y += yPos;
			shape.setPosition(positions);
		}

		void draw(RenderWindow* win) {
			win->draw(shape);
		}

	};*/

	class Game {
		RenderWindow* win;
		Event ev;
		Pacman paccy;
		Pinky* gs;

		void initvar() {
			this->win = nullptr;
		}
		void initwindow() {
			this->win = new RenderWindow(VideoMode(700, 400), "PACMAN", Style::Titlebar | Style::Close);
			this->win->setFramerateLimit(60);
		}
	public:
		Game() {
			this->initvar();
			this->initwindow();
			paccy.setScreen(win->getSize());
			paccy.color();
		}
		const bool running()const
		{
			return this->win->isOpen();
		}
		void pollevents() {
			while (this->win->pollEvent(this->ev))
			{
				if (ev.type == Event::Closed)
					this->win->close();
			}
		}
		void update() {
			this->pollevents();
		}
		void render() {
			gs->update();
			paccy.update();
			this->win->clear();
			paccy.draw(this->win);
			//gst.draw(this->win);
			gs->draw(this->win);

			this->win->display();
		}
		virtual ~Game() {
			delete this->win;
		}
	};
	int main() {
		//srand(static_cast<unsigned>(time(0)));
		Game g;
		while (g.running())
		{
			g.update();
			g.render();
		}
		return 0;
	}
	
