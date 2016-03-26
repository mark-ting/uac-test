#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <tuple>

int main(void)
{
	// Format: Weapon (Name, Damage, Cooldown, JamChance);
	std::tuple<std::string, int, float, float> selected;
	std::tuple<std::string, int, float, float> uac2 ("UAC2", 2, 0.72, 0.14);
	std::tuple<std::string, int, float, float> uac5 ("UAC5", 5, 1.66, 0.15);
	std::tuple<std::string, int, float, float> uac10 ("UAC10", 10, 2.5, 0.16);
	std::tuple<std::string, int, float, float> uac20 ("UAC20", 20, 4.0, 0.17);
	
	// Choose which UAC to use here
	selected = uac2;
	
	// Firing Cycles (Rounds/Volleys)
	// ProTip: Pick a large number so that DPS converges and you can excel graph it all pretty-like
	int loop_max = 100000;
	
	std::default_random_engine rand;
	std::uniform_real_distribution<double> dist(0.0, 1.0);
	
	double damage_dealt = 0.0;
	double time_elapsed = 0.0;
	
	int damage = std::get<1> (selected);
	double cooldown = std::get<2> (selected);
	double jam_chance = std::get<3> (selected); // use 0 for maximum double-tap rngesus power TROLOLOL ayyylmao

	std::ofstream logfile;
	logfile.open(std::get<0> (selected) + ".csv");
	logfile << "time,damage,dps" << std::endl;

	bool stop = false;
	int loop = 0;
	
	// Main Firing logic loop
	while (!stop)
	{
		logfile << time_elapsed << "," << damage_dealt << "," << (damage_dealt / time_elapsed) << std::endl;
		
		damage_dealt += damage;
		
		double jam_test;
		jam_test = dist(rand);
		std::cout << jam_test << std::endl;
		
		if (jam_test > jam_chance) {
			damage_dealt += damage;
		} else {
			// JAMMED!
			// add 5 seconds to time before next cycle
			time_elapsed += 5.0;
		}
		
		// cycle weapon
		time_elapsed += cooldown;
		
		if (loop == loop_max) {
			stop = true;
		} else {
			loop++;
		}
	}
	
	logfile.close();	
}
