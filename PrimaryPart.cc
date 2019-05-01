#include <PrimaryPart.hh>

PrimaryPart::PrimaryPart() 
{
 commandMessenger = new CommandMessenger(this); 
 GProton = new G4ParticleGun(1);
 GProton->SetParticleDefinition(G4Proton::ProtonDefinition());
 GProton->SetParticleEnergy(100. * MeV);
 GProton->SetParticlePosition(G4ThreeVector(5*mm , -5*mm, -51.*mm));
 GProton->SetParticleMomentumDirection(G4ThreeVector(0, 0, 1)); 
// GNeutron = new G4ParticleGun(1);
// GNeutron->SetParticleDefinition(G4Neutron::NeutronDefinition());

//gunMes = new GunMes(this);
}

PrimaryPart::~PrimaryPart() {}

//генерация излучения
void PrimaryPart::GeneratePrimaries(G4Event* anEvent) 
{
// GGamma->SetParticlePosition(G4ThreeVector(0, 0, 0));
 GProton->GeneratePrimaryVertex(anEvent);
 
// GNeutron->SetParticleEnergy(14. * MeV);
// GNeutron->SetParticlePosition(G4ThreeVector(0*mm , 0*mm, -21.*cm));
// GNeutron->SetParticleMomentumDirection(G4ThreeVector(0, 0, 1));
// GNeutron->GeneratePrimaryVertex(anEvent);
 
}

//GunMes::~GunMes() {};