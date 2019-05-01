//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef CommandMessenger_h
#define CommandMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class PrimaryPart;
class G4UIdirectory;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithADouble;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class CommandMessenger: public G4UImessenger
{
  public:
    explicit CommandMessenger(PrimaryPart*);
   ~CommandMessenger();
    
    void SetNewValue(G4UIcommand*, G4String);
    
  private:
    PrimaryPart* primaryPart;
    
    G4UIdirectory* primaryPartCommand;

    G4UIcmdWithADoubleAndUnit* my_cmd;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
