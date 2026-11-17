#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<iomainip>

using namespace std;

class Vehicle{
	private:
		int vehicleID;
		string vehicleType;
		int entryTime;
		int parkingDuration;
		double parkingFee;
	public:
		Vehicle();
		Vehicle(int id, string type, int time, int duration){
			vehicleID = id;
			vehicleType = type;
			entryTime = time;
			parkingDuration = duration;
		}
		int getVehicleID() const{ 
		    return vehicleID; 
		}
		void setVehicleID(int id){
			vehicleID = id;
		}
		
		string getVehicleType() const{
			return vehicleType;
		}
		void setVehicleType(string type){
			vehicleType = type;
		}
		
		int getEntryTime() const{
			return entryTime;
		}
		void setEntryTime(int time){
			entryTime = time;
		}
		
		int getDuration() const{
		    return parkingDuration;
		}
		void setDuration(int duration){
			parkingDuration = duration;
		}
		
		void calculateFee() const{
		    parkingFee = (vehicleType == "Car") ? 6.0 : (vehicleType == "Motorcycle") ? 4.0 : 2.0;
			bool rush_Hour = (entryTime >= 6 && entryTime <= 9) || (entryTime >= 15 && entryTime <= 18);
			double sum = 0;
			for(int h = 0; h < parkingDuration; ++h){
				if(h<2) sum += parkingFee * (rush_Hour?1.30:0.95);
				else sum += parkingFee * 0.9;
			}
			return sum;
		}
		void display() const{
			cout<<" ID:"<<vehicleID<<"|"
			<<vehicleType<<"|"
			<<entryTime<<"h|"
			<<parkingDuration<<"h"
			<<"|Fee: $"<<fixed
			<<setprecision(2)<<calculateFee()
			<<"\n";
		}
};
class Parkinglot{
	private:
		int parkID;
		char size;
		static const int MAX_VEHICLES = 3;
		Vehicle vehicles[MAX_VEHICLES];
		int currentVehicleCount;
	public:
		Parkinglot();
		Parkinglot(int id, char s){
			parkID = id;
			size = s;
		}
		bool isFull() const{
			int capacity = (size == 'S')?1:(size == 'M')?2:3;
			return currentVehicleCount >= capacity;
		}
		bool addVehicle(const Vehicle& v){
			if(isFull()) return false;
			vehicle[currentVehicleCount] = v;
			currentVehicleCount++;
			return true;
		}
		int findVehicleIndex(int vID) const{
			for(int i = 0; i < currentVehicleCount; i++){
				if(vehicles[i].getVehicleID() == vID){
					return i;
				}
			}
			return -1;
		}
		bool removeVehicle(int vID){
			int index = findVehicleIndex(vID);
			if(index == -1)
				return false;
			for(int i = index; i < currentVehicleCount - 1; i++){
				vehicles[i] = vehicles[i + 1];
			}
			currentVehicleCount--;
			return true;
		}
		
};

int main(){
	
}
