#ifndef AGENT_H
#define AGENT_H

#include <vector>

using std::vector;

class Agent {
    private:
        int impulse;
        char role; int playerNum;
        Game* game;
        vector<vector<double>> trustMatrix; // Only use Vector[0]
        vector<double> roleTheory;
        // vector<vector<int>> perciTheory; bool isPerciNeeded;
        // G, E, 0

    public:
        Agent();
        void setRole (char r);
        void setKnowledge (vector<vector<int>> info);
        void setKnowledgePerci (vector<vector<int>> info);

        /* For use w/ Game deliberate() */
        // void analyze ();
        // void argue ();

        /* For use w/ Game phase */
        vector<int> createParty();
        void reviewParty ();
        bool voteParty ();
        void reviewPartyResults (vector<bool> votes);
        bool voteMission ();
        void reviewMissionResults (vector<int> votes, vector<bool> pVotes); // v[0] = # Success, v[1] = # Fail
        
        /*
                    TR = t(trust) * r(role)
               Inital Review
               RP(): m1_ ModTrust: PartyRating = L*TR(l) + "CurParty" * TR
               VP(): m2_ ModTrust: PartyRating * VP_Mod * Votes[Good/Bad]
               MR(): m3_ ModTrust: "CurParty" * (S/F) * Trust
                     m4_ ModRole:  RoleTheory * (S/F) * "CurParty"
                     m5_ ModTrust: Trust * (SF) * Votes[Good/Bad]
        
        */
};

#endif // AGENT_H
