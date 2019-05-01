#ifndef FINAL_PRIMARYPART_HH
#define FINAL_PRIMARYPART_HH

#include <G4VUserPrimaryGeneratorAction.hh>
#include <G4ParticleGun.hh>
#include <G4Gamma.hh>
#include <G4Proton.hh>
#include <G4Neutron.hh>
#include <G4SystemOfUnits.hh>

#include "CommandMessenger.hh"

//class G4Event;

class CommandMessenger;

class PrimaryPart: public G4VUserPrimaryGeneratorAction{
private:
 G4ParticleGun* GProton;
 G4ParticleGun* GNeutron;
 G4ParticleGun* fParticleGun;
 CommandMessenger* commandMessenger;

public:
 PrimaryPart();
~PrimaryPart();

 virtual void GeneratePrimaries(G4Event* anEvent);
 
// const G4ParticleGun* GetParticleGun() const {return fParticleGun;}

 G4ParticleGun* GetParticleGun() {return GProton;} 

};

#endif //FINAL_PRIMARYPART_HH
