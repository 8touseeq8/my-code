#include<iostream>
#include<windows.h>
#include<string>
using namespace std;
class Leader
{
public:
	string ruler_name;
	void setLeader_Name(string name)
	{
		ruler_name = name;
	}
	string getLeader_Name()
	{
		return ruler_name;
	}
};

//For kingdom 1
class Display_Map
{
	Leader L;
public:
	int choice_for_role;
	void display_Menu(int i)
	{
		if (i == 0) {
			system("color E0");
			cout << "========================================================================================================================" << endl;
			cout << "                                                STRONGHOLD: RISE OF KINGS " << endl;
			cout << "========================================================================================================================" << endl;
			cout << "Welcome, noble ruler! Enter the name of your kingdom:" << endl;
			cout << ">>";
			getline(cin, L.ruler_name);
			cout << endl;
			cout << "Enter Your Role: " << endl;
			cout << "1. King " << endl;
			cout << "2. Commander " << endl;
			cout << "3. Merchant Leader " << endl;
			cout << endl;
			cout << ">>";
			cin >> choice_for_role;
			cin.ignore();
		}
		else if (i == 1) {
			cout << "Enter Your Role: " << endl;
			cout << "1. King " << endl;
			cout << "2. Commander " << endl;
			cout << "3. Merchant Leader " << endl;
			cout << endl;
			cout << ">>";
			cin >> choice_for_role;
			cin.ignore();
			Sleep(2000);
		}
	}
	int getchoice()
	{
		return choice_for_role;
	}
	Leader getLeader()
	{
		return L;
	}

};
void Public() {
	class Peasents {
	protected:
		int totalpeasents = 40, foodQuantity = 35, jobs = 30, healthcare = 20, tax = 15;
	public:
		void peasentsstatus() {
			cout << "Total Peasents: " << totalpeasents << endl;
			cout << "Food Quantity: " << foodQuantity << "%" << endl;
			cout << "Jobs: " << jobs << "%" << endl;
			cout << "Healthcare: " << healthcare << "%" << endl;
			cout << "Tax: " << tax << "%" << endl;
		}
		void viewneeds() {
			cout << "Need Less Tax \n";
			cout << "Need More Jobs \n";
			cout << "Need Medical Facilitation\n";
		}
	};
	class Merchands {
	protected:
		int totalmerchands = 30;
		int wealth = 1000;
		int healthcare = 30;
		int jobs = 45;
		int foodQuantity = 45;
		int tradeRouteSafety = 80;
		int marketDemand = 70;
		int corruptionLevel = 10;
		int briberyInfluence = 5;
	public:
		void merchandstatus() {
			cout << "Merchant's Wealth: " << wealth << endl;
			cout << "Trade Route Safety: " << tradeRouteSafety << "%" << endl;
			cout << "Jobs: " << jobs << "%" << endl;
			cout << "Healthcare: " << healthcare << "%" << endl;
			cout << "Market Demand: " << marketDemand << "%" << endl;
			cout << "Corruption Level: " << corruptionLevel << "%" << endl;
			cout << "Bribery Influence: " << briberyInfluence << "%" << endl;
		}
		void MerchandNeeds() {
			cout << "\nMerchant Needs:\n";
			cout << "- Safe Trade Routes\n";
			cout << "- High Market Demand\n";
			cout << "- Fair Prices in the Market\n";
			cout << "- Protection from Corruption and Bribery\n";
			cout << "- Access to Reliable Suppliers\n";
			cout << "- Political Stability for Trade Continuity\n";
			cout << "- Security from Robbery on Trade Routes\n";
		}
	};
	class Nobility {
	protected:
		int totalNobles = 30;
		int foodQuantity = 20;
		int healthcare = 23;
		int jobs = 25;
		int landOwnership = 70;        // % of total land
		int influenceInCourt = 80;     // % political influence
		int loyalty = 60;              // % loyalty to the king
		int taxBurden = 25;            // % tax they pay

	public:
		void nobilityStatus() {
			cout << "Total Nobles: " << totalNobles << endl;
			cout << "Land Ownership: " << landOwnership << "%" << endl;
			cout << "Influence in Court: " << influenceInCourt << "%" << endl;
			cout << "Jobs: " << jobs << "%" << endl;
			cout << "Healthcare: " << healthcare << "%" << endl;
			cout << "Loyalty to King: " << loyalty << "%" << endl;
			cout << "Tax Burden: " << taxBurden << "%" << endl;
		}

		void viewNeeds() {
			cout << "Need Lower Taxes\n";
			cout << "Desire More Political Influence\n";
			cout << "Want Protection of Their Land and Power\n";
			cout << "Dislike Equal Rights for Peasants and Merchants\n";
		}
	};

}
class King1 : public Leader // king For Player 1
{
private:
	Display_Map dm;
	int king_action;
	int treasury = 500, food_reserves = 300, military_strength = 100;
	int faction_nobles = 30, faction_merchants = 30, faction_peasants = 40;
	int total_Facilities_king1 = treasury + food_reserves + military_strength;
public:

	King1() {

	}
	friend class Commander1;
	friend class kingdom1;
	King1(string name, int j)
	{
		srand(time(0)); // Random seed
		if (j == 0)
		{
			int num_of_cand;
			cout << "Enter the Number of Candidates for King Selection upto 3: ";
			cin >> num_of_cand;
			while (num_of_cand < 1 || num_of_cand > 3) {
				cout << "Only 1 to 3 candidates allowed!\n";
				cout << "Enter the Number of Candidates for King Selection: ";
				cin >> num_of_cand;
			}
			cin.ignore();
			string candidate_name[3];
			for (int i = 0; i < num_of_cand; i++) {
				cout << "Enter Candidate " << i + 1 << ":\n";
				getline(cin, candidate_name[i]);
				setLeader_Name(candidate_name[i]);
			}
			cout << "Please wait , voting is held\n";
			Sleep(3000);
			int selected = -1;
			int vote = rand() % 100;
			if (vote <= 33 && num_of_cand >= 1)
				selected = 0;
			else if (vote > 33 && vote < 70 && num_of_cand >= 2)
				selected = 1;
			else if (vote >= 70 && vote <= 100 && num_of_cand == 3)
				selected = 2;
			else
				selected = num_of_cand - 1;

			setLeader_Name(candidate_name[selected]);
		}
	}
	void displayKing_Map()
	{
		cout << "-------------------------------------------------------" << endl;
		cout << "Congratulatuions !!! Tha King is " << getLeader_Name() << endl;
		cout << "Throne Status: Stable | Treasury: " << treasury << " Gold | Popularity: 65%" << endl;
		cout << "Factions: Nobles: " << faction_nobles << "% | Merchants: " << faction_merchants << "% | Peasants: " << faction_peasants << "%" << endl;
		cout << "Food Reserves: " << food_reserves << " units | Military Strength: " << military_strength << "%" << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << endl;
		cout << "Choose King Action: " << endl;
		cout << "1. Adjust Tax Rates" << endl;
		cout << "2. Declare War / Form Alliances" << endl;
		cout << "3. Appoint or Remove Commanders / Ministers" << endl;
		cout << "4. Hold Diplomatic Talks with Neighboring Kingdoms" << endl;
		cout << "5. Fund Public Services (Hospitals, Markets, Armories)" << endl;
		cout << "6. Audit Treasury to Catch Corruption" << endl << endl;
		cout << "<<";
		cin >> king_action;
	}
	void king_Actions()
	{
		while (king_action != 1 && king_action != 2 && king_action != 3 && king_action != 4 && king_action != 5 && king_action != 6)
		{
			cout << "Invalid Input!!! Enter Again" << endl;
			cin >> king_action;
		}
		if (king_action == 1)
		{
			int newsystem;
			cout << "Current Tax System : Flat Tax(20 %)" << endl;
			cout << "Choose new system :" << endl;
			cout << "1. Progressive(Rich pay more)" << endl;
			cout << "2. Flat(All equal)" << endl;
			cout << "3. High tax(Fast gold, high revolt risk)" << endl;
			cout << "<<";
			cin >> newsystem;
			if (newsystem == 1)
			{
				cout << "New tax set: Progressive" << endl;
				cout << "Treasury increase: +300 Gold per turn" << endl;
				treasury = treasury + 50;
				faction_nobles -= 10; // Nobles are angry with the tax
				faction_peasants += 15;//peasent are happy
				food_reserves -= 100;
				Sleep(2000);
			}
			else if (newsystem == 2)
			{
				cout << "New tax set: Flat" << endl;
				cout << "Treasury increase: +200 Gold per turn" << endl;
				treasury = treasury + 100;
				faction_nobles += 5;
				faction_peasants -= 5;
				faction_merchants += 10;
				food_reserves -= 600;
				Sleep(2000);
			}
			else if (newsystem == 3)
			{
				cout << "New tax set: High" << endl;
				cout << "Treasury increase: +100 Gold per turn" << endl;
				treasury = treasury + 100;
				faction_nobles += 20;
				faction_peasants -= 30;
				faction_merchants -= 10;
				cout << "Risk of revolt increased due to high taxes!" << endl;
				food_reserves -= 500;
				Sleep(2000);
			}
		}
		else if (king_action == 2)
		{
			int war_choice;
			cout << "Choose diplomatic stance:" << endl;
			cout << "1. Declare War on Northern Empire" << endl;
			cout << "2. Form Alliance with Eastern Traders" << endl;
			cout << "<<";
			cin >> war_choice;
			if (war_choice == 1)
			{
				cout << "War declared! All commanders put on high alert!" << endl;
				cout << "Resources allocated to military. Public opinion mixed." << endl;
				treasury -= 350;
				military_strength -= 500;
				Sleep(2000);
			}
			else if (war_choice == 2)
			{
				cout << "Alliance formed. Trade routes opened. Gold income increased!" << endl;
				cout << "Merchant faction now supportive!" << endl;
				treasury += 50;
				military_strength -= 150;
				Sleep(2000);
			}
		}
		else if (king_action == 3)
		{
			int appoint_choice;
			cout << "1. Appoint New Commander" << endl;
			cout << "2. Remove Corrupt Minister , because Military is going weak" << endl;
			cout << "<<";
			cin >> appoint_choice;
			if (appoint_choice == 1)
			{
				cout << "New commander appointed at western border." << endl;
				cout << "Military discipline expected to improve." << endl;
				treasury -= 300;
				military_strength -= 150;
				Sleep(2000);
			}
			else if (appoint_choice == 2)
			{
				cout << "Corrupt minister removed from treasury department." << endl;
				cout << "Public trust improved. Treasury loss prevented!" << endl;
				treasury += 60;
				military_strength -= 600;
			}
		}
		else if (king_action == 4)
		{
			cout << "Sending diplomatic envoys to neighboring kingdoms..." << endl;
			Sleep(3000);
			int King_Action_rand;
			King_Action_rand = rand() % 20;
			if (King_Action_rand > 0 && King_Action_rand < 10) {
				cout << "Talks successful. Peace treaty signed with Southlands!" << endl;
				cout << "Stability increased. Resources saved from war." << endl;
				treasury -= 700;
				Sleep(2000);
			}
			else {
				cout << "Signs of War !! No Talks successful \n";
				treasury -= 700;
				military_strength -= 6000;
				Sleep(2000);
			}
		}
		else if (king_action == 5)
		{
			int fund_choice;
			cout << "Where do you want to invest funds?" << endl;
			cout << "1. Hospitals (+Health)" << endl;
			cout << "2. Markets (+Economy)" << endl;
			cout << "3. Armories (+Military Readiness)" << endl;
			cout << "<<";
			cin >> fund_choice;
			if (fund_choice == 1)
			{
				cout << "Hospitals upgraded. Disease control improved!" << endl;
				treasury = treasury - 800;
				Sleep(2000);
			}
			else if (fund_choice == 2)
			{
				cout << "Markets boosted. Economy flourishes!" << endl;
				treasury = treasury - 800;
			}
			else if (fund_choice == 3)
			{
				cout << "Armories stocked. Army readiness increased!" << endl;
				treasury = treasury - 900;
				Sleep(2000);
			}
		}
		else if (king_action == 6)
		{
			cout << "Initiating audit of treasury..." << endl;
			Sleep(3000);
			cout << "Corruption discovered in supply chain!" << endl;
			cout << "Guilty officials punished. 100 Gold recovered!" << endl;
			treasury += 100;
			Sleep(2000);
		}
		total_Facilities_king1 = treasury + food_reserves + military_strength;
	}

};
class Commander1 : public Leader
{
private:
	int infantry = 300, Archers = 150, Cavalry = 80, Army_budget = 700;
	int Commander_Action_Choice;
	int total_facilities_Commander1 = Army_budget;

	Display_Map dm;
public:
	Commander1() {}
	Commander1(string name) {
		setLeader_Name(name); // From parent class
	}
	friend class kingdom1;
	void displayCommander_Map()
	{
		cout << "-------------------------------------------------------" << endl;
		cout << "Role: Commander of the Royal Army" << endl;
		cout << "Kingdom: " << getLeader_Name() << endl;
		cout << "Assigned Region: Eastern Border (Tense Area)" << endl;
		cout << "Current Army Status: " << endl;
		cout << "infantry: " << infantry << endl;
		cout << "Archers: " << Archers << endl;
		cout << "Cavalry: " << Cavalry << endl;
		cout << "Army Budget: " << Army_budget << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << endl << endl;
		cout << "Choose Your First Strategic Action: " << endl;
		cout << "1.  Train more soldiers (costs gold + time)" << endl;
		cout << "2.  Fortify the border defenses (walls, watchtowers)" << endl;
		cout << "3.  Send scouts to gather enemy intel" << endl;
		cout << "4.  Increase rations to raise army morale" << endl;
		cout << "5.  Launch a surprise attack ( high risk)" << endl;
		cout << "6.  Request more resources from the King" << endl;
		cout << "<<";
		cin >> Commander_Action_Choice;
	}
	void Commander_Actions()
	{
		King1 king;
		while (Commander_Action_Choice != 1 && Commander_Action_Choice != 2 && Commander_Action_Choice != 3 && Commander_Action_Choice != 4 && Commander_Action_Choice != 5 && Commander_Action_Choice != 6)
		{
			cout << "Invalid Input!!! Enter Again:";
			cin >> Commander_Action_Choice;
		}
		if (Commander_Action_Choice == 1)
		{
			cout << "----------Training initiated----------" << endl;
			cout << "Estimated time: 5 seconds " << endl;
			Sleep(3000);
			cout << "Gold spent: 300" << endl;
			king.treasury -= 700;
			cout << "+100 Soldiers added to the army" << endl;
			infantry += 15;
			cout << "Morale: Slightly increased" << endl;
			Archers -= 10;
			Cavalry -= 10;
			Army_budget -= 500;
			Sleep(2000);
		}
		else if (Commander_Action_Choice == 2)
		{
			cout << "----------Fortifying border----------" << endl;
			cout << "3 Watchtowers constructed" << endl;
			cout << " Walls reinforced" << endl;
			cout << "Resources used: Wood, Stone, Gold" << endl;
			cout << "Time taken: 15 seconds" << endl;
			Sleep(5000);
			cout << "Defensive rating increased!" << endl;
			king.treasury -= 200;
			Army_budget -= 200;
		}
		else if (Commander_Action_Choice == 3)
		{
			cout << "----------Scouts deployed to enemy territory----------" << endl;
			cout << "Scouting in progress " << endl;
			Sleep(5000);
			cout << "Report received:" << endl;
			cout << "-Enemy army strength: 250" << endl;
			cout << "- Weak flank: Southern hill" << endl;
			Archers -= 15;
			Cavalry -= 10;
			Army_budget -= 800;
		}
		else if (Commander_Action_Choice == 4)
		{
			cout << "----------Rations doubled for 2 days!----------" << endl;
			cout << "Food stock decreased by 200 units" << endl;
			cout << "Morale increased to HIGH" << endl;
			king.food_reserves -= 50;
			Army_budget -= 300;
			Sleep(2000);
		}
		else if (Commander_Action_Choice == 5)
		{
			cout << "----------Surprise attack launched on enemy camp!----------" << endl;
			int surprise_attack_result;
			cout << "Enter 1 to Attack in Night , 2 for Attack in Morning:";
			cin >> surprise_attack_result;
			while (surprise_attack_result != 1 && surprise_attack_result != 2) {
				cout << "!!!Enter Attack Time Again!!!";
				cin >> surprise_attack_result;
			}
			if (surprise_attack_result == 1)
			{
				cout << "Outcomes:" << endl;
				cout << "- Victory! Enemy camp destroyed!" << endl;
				cout << "- Losses: 50 soldiers, 20 archers" << endl;
				cout << "- Loot gained : 500 Gold, 100 food units" << endl;
				king.treasury += 200;
				Archers -= 25;
				Cavalry -= 20;
				Army_budget -= 600;
				Sleep(2000);
			}
			else if (surprise_attack_result == 2)
			{
				cout << "Outcomes:" << endl;
				cout << "-Ambush Failed!" << endl;
				cout << "-Enemy was prepared. Heavy losses!" << endl;
				cout << "-Army morale dropped." << endl;
				Cavalry -= 30;
				Archers -= 25;
				king.treasury -= 200;
				king.military_strength -= 30;
				Army_budget -= 650;
				Sleep(2000);
			}
		}
		else if (Commander_Action_Choice == 6)
		{
			cout << "----------Sending request to King----------" << endl;
			int kinghelp_choice;
			cout << "Enter 1 to request King through Call and 2 to request King through Message:";
			cin >> kinghelp_choice;
			while (kinghelp_choice != 1 && kinghelp_choice != 2)
			{
				cout << "Invalid Input!! Enter Again";
				cin >> kinghelp_choice;
			}
			if (kinghelp_choice == 2)
			{
				cout << "Message: Requesting 500 gold and 300 food units." << endl;
				cout << "Denied. Court claims budget shortage." << endl;
				Sleep(2000);
			}
			else if (kinghelp_choice == 1)
			{
				cout << "Call: Requesting 500 gold and 300 food units. " << endl;
				cout << "Approved. Resources added." << endl;
				Army_budget += 100;
				Sleep(2000);
			}
			total_facilities_Commander1 = infantry + Archers + Cavalry + Army_budget;
		}
	}

};
class MerchantLeader1 : public Leader
{
private:
	int merchant_action = 0;
	int gold = 800, food_stock = 600, trade_routes = 2, market_rating = 70;
	int MerchandLeader1_Facilities = gold + food_stock;
public:
	MerchantLeader1() {}
	MerchantLeader1(string name) {
		setLeader_Name(name);
	}
	friend class kingdom1;
	void displayMerchant_Map()
	{
		cout << "-------------------------------------------------------" << endl;
		cout << "Role: Merchant Guild Leader" << endl;
		cout << "Kingdom: " << getLeader_Name() << endl;
		cout << "Trade Gold: " << gold << " | Food Stock: " << food_stock << " units" << endl;
		cout << "Active Trade Routes: " << trade_routes << endl;
		cout << "Market Rating: " << market_rating << "%" << endl;
		cout << "Allies: Eastern Traders | Rivals: Desert Nomads" << endl;
		cout << "-------------------------------------------------------" << endl << endl;

		cout << "Choose Your Trade Action:" << endl;
		cout << "1. Establish New Trade Route" << endl;
		cout << "2. Upgrade Marketplaces" << endl;
		cout << "3. Organize a Grand Trade Fair" << endl;
		cout << "4. Deal with Black Market Activity" << endl;
		cout << "5. Import Resources (food, weapons)" << endl;
		cout << "6. Bribe Nobles for Policy Favors" << endl;
		cout << "<<";
		cin >> merchant_action;
	}

	void merchant_Actions()
	{
		switch (merchant_action)
		{
		case 1:
			cout << "Establishing trade route with Western Empire..." << endl;
			Sleep(3000);
			cout << "Route secured! +100 gold/turn. Risk of bandits increased!" << endl;
			gold += 100;
			break;

		case 2:
			cout << "Markets being upgraded with stone roads and guards..." << endl;
			Sleep(3000);
			cout << "Market rating increased to 85%! Citizens more active in trade." << endl;
			cout << "200 Gold Used \n";
			gold -= 600;
			break;

		case 3:
			cout << "Organizing Grand Trade Fair in Capital..." << endl;
			Sleep(3000);
			cout << "Success! +200 gold profit. Foreign traders impressed!" << endl;
			gold += 50;
			food_stock -= 750;
			break;

		case 4:
			cout << "Launching crackdown on illegal smuggling..." << endl;
			Sleep(3000);
			cout << "20 smugglers arrested. 200 gold recovered. Nobles slightly annoyed." << endl;
			gold += 50;
			food_stock -= 500;
			break;

		case 5:
			int import_choice;
			cout << "Choose what to import: \n1. Food \n2. Weapons\n<<";
			cin >> import_choice;
			if (import_choice == 1)
			{
				cout << "+200 food imported from Southern Plains." << endl;
				cout << "-700 gold spent." << endl;
				gold -= 700;
				food_stock += 2000;
				Sleep(2000);
			}
			else if (import_choice == 2)
			{
				cout << "+150 weapons imported from Dwarven Traders." << endl;
				cout << "-700 gold spent." << endl;
				gold -= 700;
				food_stock -= 150;
				Sleep(2000);
			}
			break;

		case 6:
			cout << "Sending gold-filled gifts to Nobles..." << endl;
			Sleep(2000);
			cout << "Policy changed: Lower tax on merchants passed!" << endl;
			cout << "-400 gold used, but long-term profit assured." << endl;
			gold -= 400;
			food_stock -= 200;
			Sleep(2000);
			break;

		default:
			cout << "Invalid Action. No change." << endl;
		}
		MerchandLeader1_Facilities = gold + food_stock;
	}
};
class kingdom1
{
	int TotalKingdom1_Budget;
public:
	kingdom1() {}
	King1 king1;
	Commander1 commander1;
	MerchantLeader1 merchantLeader1;
	int totalbudgetk1() {
		TotalKingdom1_Budget = king1.total_Facilities_king1 + commander1.total_facilities_Commander1 + merchantLeader1.MerchandLeader1_Facilities;
		return TotalKingdom1_Budget;
	}
};


// For KingDome 2
class King2 : public Leader // king For Player 1
{
private:
	Display_Map dm;
	int king_action;
	int treasury = 600, food_reserves = 350, military_strength = 50;
	int faction_nobles = 30, faction_merchants = 30, faction_peasants = 40;
	int total_Facilities_king2 = treasury + food_reserves + military_strength;
public:

	King2() {

	}
	friend class Commander2;
	friend class kingdom2;
	King2(string name, int j) {
		srand(time(0)); // Random seed
		if (j == 0)
		{
			int num_of_cand;
			cout << "Enter the Number of Candidates for King Selection upto 3: ";
			cin >> num_of_cand;
			while (num_of_cand < 1 || num_of_cand > 3) {
				cout << "Only 1 to 3 candidates allowed!\n";
				cout << "Enter the Number of Candidates for King Selection: ";
				cin >> num_of_cand;
			}
			cin.ignore();
			string candidate_name[3];
			for (int i = 0; i < num_of_cand; i++) {
				cout << "Enter Candidate " << i + 1 << ":\n";
				getline(cin, candidate_name[i]);
				setLeader_Name(candidate_name[i]);
			}
			cout << "Please wait , voting is held\n";
			Sleep(3000);
			int selected = -1;
			int vote = rand() % 100;
			if (vote <= 33 && num_of_cand >= 1)
				selected = 0;
			else if (vote > 33 && vote < 70 && num_of_cand >= 2)
				selected = 1;
			else if (vote >= 70 && vote <= 100 && num_of_cand == 3)
				selected = 2;
			else
				selected = num_of_cand - 1;

			setLeader_Name(candidate_name[selected]);
		}
	}
	void displayKing_Map()
	{
		cout << "-------------------------------------------------------" << endl;
		cout << "Congratulatuions !!! Tha King is " << getLeader_Name() << endl;
		cout << "Throne Status: Stable | Treasury: " << treasury << " Gold | Popularity: 65%" << endl;
		cout << "Factions: Nobles: " << faction_nobles << "% | Merchants: " << faction_merchants << "% | Peasants: " << faction_peasants << "%" << endl;
		cout << "Food Reserves: " << food_reserves << " units | Military Strength: " << military_strength << "%" << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << endl;
		cout << "Choose King Action: " << endl;
		cout << "1. Adjust The Tax Rates" << endl;
		cout << "2. Declare War At Enemy" << endl;
		cout << "3. Appoint or Remove Commanders / Ministers" << endl;
		cout << "4. Hold Diplomatic Talks with Neighboring Kingdoms" << endl;
		cout << "5. Fund Public Services (Hospitals, Markets, Armories)" << endl;
		cout << "6. Audit Treasury to Catch Corruption" << endl << endl;
		cout << "<<";
		cin >> king_action;
	}
	void king_Actions()
	{
		while (king_action != 1 && king_action != 2 && king_action != 3 && king_action != 4 && king_action != 5 && king_action != 6)
		{
			cout << "Invalid Input!!! Enter Again" << endl;
			cin >> king_action;
		}
		if (king_action == 1)
		{
			int newsystem;
			cout << "Current Tax System : Flat Tax(20 %)" << endl;
			cout << "Choose new system :" << endl;
			cout << "1. Progressive(Rich pay more)" << endl;
			cout << "2. Flat(All equal)" << endl;
			cout << "3. High tax(Fast gold, high revolt risk)" << endl;
			cout << "<<";
			cin >> newsystem;
			if (newsystem == 1)
			{
				cout << "New tax set: Progressive" << endl;
				cout << "Treasury increase: +300 Gold per turn" << endl;
				treasury = treasury + 100;
				faction_nobles -= 20; // Nobles are angry with the tax
				faction_peasants += 15;//peasent are happy
				food_reserves -= 50;
				Sleep(2000);
			}
			else if (newsystem == 2)
			{
				cout << "New tax set: Flat" << endl;
				cout << "Treasury increase: +50 Gold per turn" << endl;
				treasury = treasury + 50;
				faction_nobles += 5;
				faction_peasants -= 5;
				faction_merchants += 10;
				Sleep(2000);
			}
			else if (newsystem == 3)
			{
				cout << "New tax set: High" << endl;
				cout << "Treasury increase: +100 Gold per turn" << endl;
				treasury = treasury + 100;
				faction_nobles += 20;
				faction_peasants -= 30;
				faction_merchants -= 10;
				food_reserves -= 700;
				cout << "Risk of revolt increased due to high taxes!" << endl;
				Sleep(2000);
			}
		}
		else if (king_action == 2)
		{
			int war_choice;
			cout << "Choose diplomatic stance:" << endl;
			cout << "1. Declare War on Northern Empire" << endl;
			cout << "2. Form Alliance with Eastern Traders" << endl;
			cout << "<<";
			cin >> war_choice;
			if (war_choice == 1)
			{
				cout << "War declared! All commanders put on high alert!" << endl;
				cout << "Resources allocated to military. Public opinion mixed." << endl;
				treasury -= 900;
				food_reserves -= 500;
				Sleep(2000);
			}
			else if (war_choice == 2)
			{
				cout << "Alliance formed. Trade routes opened. Gold income increased!" << endl;
				cout << "Merchant faction now supportive!" << endl;
				treasury -= 900;
				food_reserves -= 450;
				Sleep(2000);
			}
		}
		else if (king_action == 3)
		{
			int appoint_choice;
			cout << "1. Appoint New Commander" << endl;
			cout << "2. Remove Corrupt Minister , because Military is going weak" << endl;
			cout << "<<";
			cin >> appoint_choice;
			if (appoint_choice == 1)
			{
				cout << "New commander appointed at western border." << endl;
				cout << "Military discipline expected to improve." << endl;
				military_strength -= 600;
				Sleep(2000);
			}
			else if (appoint_choice == 2)
			{
				cout << "Corrupt minister removed from treasury department." << endl;
				cout << "Public trust improved. Treasury loss prevented!" << endl;
				treasury += 50;
				Sleep(2000);
			}
		}
		else if (king_action == 4)
		{
			cout << "Sending diplomatic envoys to neighboring kingdoms..." << endl;
			Sleep(3000);
			int King_Action_rand;
			King_Action_rand = rand() % 20;
			if (King_Action_rand > 0 && King_Action_rand < 10) {
				cout << "Talks successful. Peace treaty signed with Southlands!" << endl;
				cout << "Stability increased. Resources saved from war." << endl;
				treasury -= 600;
				Sleep(2000);
			}
			else {
				cout << "Signs of War !! No Talks successful \n";
				treasury -= 800;
				Sleep(2000);
			}
		}
		else if (king_action == 5)
		{
			int fund_choice;
			cout << "Where do you want to invest funds?" << endl;
			cout << "1. Hospitals (+Health)" << endl;
			cout << "2. Markets (+Economy)" << endl;
			cout << "3. Armories (+Military Readiness)" << endl;
			cout << "<<";
			cin >> fund_choice;
			if (fund_choice == 1)
			{
				cout << "Hospitals upgraded. Disease control improved!" << endl;
				treasury = treasury - 800;
				Sleep(2000);
			}
			else if (fund_choice == 2)
			{
				cout << "Markets boosted. Economy flourishes!" << endl;
				treasury = treasury - 900;
				Sleep(2000);
			}
			else if (fund_choice == 3)
			{
				cout << "Armories stocked. Army readiness increased!" << endl;
				treasury = treasury - 900;
				Sleep(2000);
			}
		}
		else if (king_action == 6)
		{
			cout << "Initiating audit of treasury..." << endl;
			Sleep(3000);
			cout << "Corruption discovered in supply chain!" << endl;
			cout << "Guilty officials punished. 100 Gold recovered!" << endl;
			treasury -= 800;
			Sleep(2000);
		}
		total_Facilities_king2 = treasury + food_reserves + military_strength;
	}
};
class Commander2 : public Leader
{
private:
	int infantry = 300, Archers = 150, Cavalry = 80, Army_budget = 700;
	int Commander_Action_Choice;
	int total_facilities_Commander2 = Army_budget;
	Display_Map dm;
public:
	Commander2() {}
	Commander2(string name) {
		setLeader_Name(name); // From parent class
	}
	friend class kingdom2;
	void displayCommander_Map()
	{
		cout << "-------------------------------------------------------" << endl;
		cout << "Role: Commander of the Royal Army" << endl;
		cout << "Kingdom: " << getLeader_Name() << endl;
		cout << "Assigned Region: Eastern Border (Tense Area)" << endl;
		cout << "Current Army Status: " << endl;
		cout << "infantry: " << infantry << endl;
		cout << "Archers: " << Archers << endl;
		cout << "Cavalry: " << Cavalry << endl;
		cout << "Army Budget: " << Army_budget << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << endl << endl;
		cout << "Choose Your First Strategic Action: " << endl;
		cout << "1.  Train more soldiers (costs gold + time)" << endl;
		cout << "2.  Fortify the border defenses (walls, watchtowers)" << endl;
		cout << "3.  Send scouts to gather enemy intel" << endl;
		cout << "4.  Increase rations to raise army morale" << endl;
		cout << "5.  Launch a surprise attack ( high risk)" << endl;
		cout << "6.  Request more resources from the King" << endl;
		cout << "<<";
		cin >> Commander_Action_Choice;
	}
	void Commander_Actions()
	{
		King2 king;
		while (Commander_Action_Choice != 1 && Commander_Action_Choice != 2 && Commander_Action_Choice != 3 && Commander_Action_Choice != 4 && Commander_Action_Choice != 5 && Commander_Action_Choice != 6)
		{
			cout << "Invalid Input!!! Enter Again:";
			cin >> Commander_Action_Choice;
		}
		if (Commander_Action_Choice == 1)
		{
			cout << "----------Training initiated----------" << endl;
			cout << "Estimated time: 5 seconds " << endl;
			Sleep(3000);
			cout << "Gold spent: 300" << endl;
			king.treasury -= 700;
			cout << "+100 Soldiers added to the army" << endl;
			infantry += 15;
			cout << "Morale: Slightly increased" << endl;
			Archers -= 10;
			Cavalry -= 10;
			Sleep(2000);
		}
		else if (Commander_Action_Choice == 2)
		{
			cout << "----------Fortifying border----------" << endl;
			cout << "3 Watchtowers constructed" << endl;
			cout << " Walls reinforced" << endl;
			cout << "Resources used: Wood, Stone, Gold" << endl;
			cout << "Time taken: 15 seconds" << endl;
			Sleep(5000);
			cout << "Defensive rating increased!" << endl;
			king.treasury = -800;
			Army_budget -= 150;
			Sleep(2000);
		}
		else if (Commander_Action_Choice == 3)
		{
			cout << "----------Scouts deployed to enemy territory----------" << endl;
			cout << "Scouting in progress " << endl;
			Sleep(5000);
			cout << "Report received:" << endl;
			cout << "-Enemy army strength: 250" << endl;
			cout << "- Weak flank: Southern hill" << endl;
			Archers -= 15;
			Cavalry -= 10;
			Army_budget -= 900;
			Sleep(2000);
		}
		else if (Commander_Action_Choice == 4)
		{
			cout << "----------Rations doubled for 2 days!----------" << endl;
			cout << "Food stock decreased by 200 units" << endl;
			cout << "Morale increased to HIGH" << endl;
			king.food_reserves -= 50;
			Army_budget -= 200;
			Sleep(2000);
		}
		else if (Commander_Action_Choice == 5)
		{
			cout << "----------Surprise attack launched on enemy camp!----------" << endl;
			int surprise_attack_result;
			cout << "Enter 1 to Attack in Night , 2 for Attack in Morning:";
			cin >> surprise_attack_result;
			while (surprise_attack_result != 1 && surprise_attack_result != 2) {
				cout << "!!!Enter Attack Time Again!!!";
				cin >> surprise_attack_result;
			}
			if (surprise_attack_result == 1)
			{
				cout << "Outcomes:" << endl;
				cout << "- Victory! Enemy camp destroyed!" << endl;
				cout << "- Losses: 50 soldiers, 20 archers" << endl;
				cout << "- Loot gained : 500 Gold, 100 food units" << endl;
				king.treasury += 200;
				Archers -= 25;
				Cavalry -= 20;
				Army_budget -= 750;
				Sleep(3000);
			}
			else if (surprise_attack_result == 2)
			{
				cout << "Outcomes:" << endl;
				cout << "-Ambush Failed!" << endl;
				cout << "-Enemy was prepared. Heavy losses!" << endl;
				cout << "-Army morale dropped." << endl;
				cout << "~~~~~The KING died~~~~~" << endl;
				cout << "#%#%#% Held Elections Again #%#%#% \n";
				int j = 0;
				Display_Map DM;
				King2 king2(DM.getLeader().getLeader_Name(), j);
				Cavalry -= 30;
				Archers -= 25;
				king.treasury -= 200;
				king.military_strength -= 30;
				Army_budget -= 800;
				Sleep(3000);
			}
		}
		else if (Commander_Action_Choice == 6)
		{
			cout << "----------Sending request to King----------" << endl;
			int kinghelp_choice;
			cout << "Enter 1 to request King through Call and 2 to request King through Message:";
			cin >> kinghelp_choice;
			while (kinghelp_choice != 1 && kinghelp_choice != 2)
			{
				cout << "Invalid Input!! Enter Again";
				cin >> kinghelp_choice;
			}
			if (kinghelp_choice == 2)
			{
				cout << "Message: Requesting 500 gold and 300 food units." << endl;
				cout << "Denied. Court claims budget shortage." << endl;
				Sleep(2000);
			}
			else if (kinghelp_choice == 1)
			{
				cout << "Call: Requesting 500 gold and 300 food units. " << endl;
				cout << "Approved. Resources added." << endl;
				Army_budget += 750;
				Sleep(2000);
			}
			total_facilities_Commander2 = infantry + Archers + Cavalry + Army_budget;
		}
	}

};
class MerchantLeader2 : public Leader
{
private:
	int merchant_action = 0;
	int gold = 700, food_stock = 700, trade_routes = 2, market_rating = 70;
	int MerchandLeader2_Facilities = gold + food_stock;
public:
	MerchantLeader2() {}
	MerchantLeader2(string name) {
		setLeader_Name(name);
	}
	friend class kingdom2;
	void displayMerchant_Map()
	{
		cout << "-------------------------------------------------------" << endl;
		cout << "Role: Merchant Guild Leader" << endl;
		cout << "Kingdom: " << getLeader_Name() << endl;
		cout << "Trade Gold: " << gold << " | Food Stock: " << food_stock << " units" << endl;
		cout << "Active Trade Routes: " << trade_routes << endl;
		cout << "Market Rating: " << market_rating << "%" << endl;
		cout << "Allies: Eastern Traders | Rivals: Desert Nomads" << endl;
		cout << "-------------------------------------------------------" << endl << endl;

		cout << "Choose Your Trade Action:" << endl;
		cout << "1. Establish New Trade Route" << endl;
		cout << "2. Upgrade Marketplaces" << endl;
		cout << "3. Organize a Grand Trade Fair" << endl;
		cout << "4. Deal with Black Market Activity" << endl;
		cout << "5. Import Resources (food, weapons)" << endl;
		cout << "6. Bribe Nobles for Policy Favors" << endl;
		cout << "<<";
		cin >> merchant_action;
	}

	void merchant_Actions()
	{
		switch (merchant_action)
		{
		case 1:
			cout << "Establishing trade route with Western Empire..." << endl;
			Sleep(3000);
			cout << "Route secured! +250 gold/turn. Risk of bandits increased!" << endl;
			gold += 250;
			break;

		case 2:
			cout << "Markets being upgraded with stone roads and guards..." << endl;
			Sleep(3000);
			cout << "Market rating increased to 85%! Citizens more active in trade." << endl;
			gold += 150;
			break;

		case 3:
			cout << "Organizing Grand Trade Fair in Capital..." << endl;
			Sleep(3000);
			cout << "Success! +200 gold profit. Foreign traders impressed!" << endl;
			gold += 200;
			break;

		case 4:
			cout << "Launching crackdown on illegal smuggling..." << endl;
			Sleep(3000);
			cout << "20 smugglers arrested. 100 gold recovered. Nobles slightly annoyed." << endl;
			gold += 100;
			break;

		case 5:
			int import_choice;
			cout << "Choose what to import: \n1. Food \n2. Weapons\n<<";
			cin >> import_choice;
			if (import_choice == 1)
			{
				cout << "+500 food imported from Southern Plains." << endl;
				cout << "-300 gold spent." << endl;
				gold -= 300;
				Sleep(2000);
			}
			else if (import_choice == 2)
			{
				cout << "+150 weapons imported from Dwarven Traders." << endl;
				cout << "-500 gold spent." << endl;
				gold -= 800;
				Sleep(2000);
			}
			break;

		case 6:
			cout << "Sending gold-filled gifts to Nobles..." << endl;
			Sleep(2000);
			cout << "Policy changed: Lower tax on merchants passed!" << endl;
			cout << "-300 gold used, but long-term profit assured." << endl;
			gold -= 850;
			break;

		default:
			cout << "Invalid Action. No change." << endl;
		}
		MerchandLeader2_Facilities = gold + food_stock;
	}
};
class kingdom2
{
	int TotalKingdom2_Budget;
public:
	kingdom2() {
	}
	King2 king2;
	Commander2 commander2;
	MerchantLeader2 merchantLeader2;
	int totalbudgetk2() {
		TotalKingdom2_Budget = king2.total_Facilities_king2 + commander2.total_facilities_Commander2 + merchantLeader2.MerchandLeader2_Facilities;
		return TotalKingdom2_Budget;
	}

};


// To Select Leader
void leaderSelection() {
	Display_Map DM;
	int i;
	i = 0;
	DM.display_Menu(i);
	int Leaderchoice = DM.getchoice();
	while (Leaderchoice != 1 && Leaderchoice != 2 && Leaderchoice != 3) {
		cout << "Invalid Input!! Enter Again" << endl;
		cout << ">>";
		cin >> Leaderchoice;
	}
	kingdom1 k1;
	kingdom2 k2;
	int budget_kingdom1 = k1.totalbudgetk1();
	int budget_kingdom2 = k2.totalbudgetk2();

	i = 1;
	int j;
	j = 0;
	while (k1.totalbudgetk1() > 2000 || k2.totalbudgetk2() > 2000)
	{
		if (Leaderchoice == 1) // For King
		{
			cout << "+++++PLAYER 1 AS A KING+++++" << endl;
			system("color B0");
			King1 king1(DM.getLeader().getLeader_Name(), j);
			king1.displayKing_Map();
			king1.king_Actions();
			cout << endl;
			system("cls");
			system("color 80");
			cout << "+++++PLAYER 2 AS A KING +++++" << endl;
			King2 king2(DM.getLeader().getLeader_Name(), j);
			king2.displayKing_Map();
			king2.king_Actions();
			Sleep(3000);
			system("cls");
			DM.display_Menu(i);
			Leaderchoice = DM.getchoice();
			j++;
		}
		else if (Leaderchoice == 2) // For Commander
		{
			cout << "+++++PLAYER 1 AS A COMMANDER+++++" << endl;
			system("cls");
			system("color 90");
			Commander1 commander1(DM.getLeader().getLeader_Name());
			commander1.displayCommander_Map();
			commander1.Commander_Actions();
			cout << endl;
			system("cls");
			system("color 80");
			cout << "+++++PLAYER 2 AS A COMMANDER+++++" << endl;
			Commander2 commander2(DM.getLeader().getLeader_Name());
			commander2.displayCommander_Map();
			commander2.Commander_Actions();
			Sleep(3000);
			system("cls");
			DM.display_Menu(i);
			Leaderchoice = DM.getchoice();
		}
		else if (Leaderchoice == 3)
		{
			cout << "+++++PLAYER 1 AS A MERCHAND LEADER+++++" << endl;
			system("cls");
			system("color 60");
			MerchantLeader1 merchant1(DM.getLeader().getLeader_Name());
			merchant1.displayMerchant_Map();
			merchant1.merchant_Actions();
			cout << endl;
			system("cls");
			system("color B0");
			cout << "+++++PLAYER 2 AS A MERCHAND LEADER+++++" << endl;
			MerchantLeader2 merchant2(DM.getLeader().getLeader_Name());
			merchant2.displayMerchant_Map();
			merchant2.merchant_Actions();
			Sleep(3000);
			system("cls");
			DM.display_Menu(i);
			Leaderchoice = DM.getchoice();
		}
		k1.totalbudgetk1();
		k2.totalbudgetk2();
	}

	system("cls");
	cout << "\n";
	cout << "****************************************\n";
	cout << "*                                      *\n";
	cout << "*            * GAME OVER *            *\n";
	cout << "*                                      *\n";
	cout << "****************************************\n";
	if (budget_kingdom1 > 100) {
		cout << "\n";
		cout << "****************************************\n";
		cout << "*                                      *\n";
		cout << "*         * PLAYER 1 WINNER *          *\n";
		cout << "*                                      *\n";
		cout << "****************************************\n";
	}
	else if (budget_kingdom2 > 100)
	{
		cout << "\n";
		cout << "****************************************\n";
		cout << "*                                      *\n";
		cout << "*         * PLAYER 2 WINNER *          *\n";
		cout << "*                                      *\n";
		cout << "****************************************\n";
	}
}
int main()
{
	leaderSelection();

}