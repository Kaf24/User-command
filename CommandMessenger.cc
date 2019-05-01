//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "CommandMessenger.hh"

#include "PrimaryPart.hh"
#include "G4UIdirectory.hh"

#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithADouble.hh"
#include "globals.hh"
using namespace std;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CommandMessenger::CommandMessenger(PrimaryPart* pP):primaryPart(pP)
{  
  primaryPartCommand = new G4UIdirectory("/PrimaryPart/");
  primaryPartCommand->SetGuidance("User Primary Particles commands");
  
  my_cmd = new G4UIcmdWithADoubleAndUnit("/PrimaryPart/my_cmd",this);
  my_cmd->SetGuidance("It's my command!");
  my_cmd->SetParameterName("Energy",true,true);
  my_cmd->SetDefaultValue(1.);  
  my_cmd->SetDefaultUnit("keV");
  my_cmd->SetUnitCandidates("ev keV MeV GeV TeV");
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CommandMessenger::~CommandMessenger()
{
  delete my_cmd;
  delete primaryPartCommand;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void CommandMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{      
 if (command == my_cmd)
 {
  this->primaryPart->GetParticleGun()->SetParticleEnergy(my_cmd->GetNewDoubleValue(newValue));
 }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
