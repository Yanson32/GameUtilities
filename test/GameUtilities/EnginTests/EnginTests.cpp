#include <catch2/catch_test_macros.hpp>
#include <GameUtilities/Engin/Engin.h>
#include <GameUtilities/Engin/Frame.h>
#include <GameUtilities/Engin/GameState.h>
#include <GameUtilities/Core/Macros.h>
class TestState: public GU::Engin::GameState
{
    public:

        /*********************************************************************************//**
        *   \brief	Initialize the game state.
        *************************************************************************************/
        virtual void init(std::shared_ptr<GU::Engin::Frame> frame) override;


        /*********************************************************************************//**
        *   \brief	Clean any resource the state uses
        *************************************************************************************/
        virtual void clean(std::shared_ptr<GU::Engin::Frame> frame) override;


        /*********************************************************************************//**
        *   \brief	This method handles input such as user input and events
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void handleEvents(GU::Engin::Engin &engin, 
                                  const float &deltaTime, 
                                  std::shared_ptr<GU::Engin::Frame> frame) override;


        /*********************************************************************************//**
        *   \brief	This method handles input such as user input and events
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void update(GU::Engin::Engin &engin, 
                            const float &deltaTime, 
                            std::shared_ptr<GU::Engin::Frame> frame) override;


        /*********************************************************************************//**
        *   \brief	This method draws the current game state.
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void draw(GU::Engin::Engin& engin, 
                          const float &deltaTime, 
                          std::shared_ptr<GU::Engin::Frame> frame) override;


        virtual ~TestState();
};



/*********************************************************************************//**
*   \brief	Initialize the game state.
*************************************************************************************/
void TestState::init(std::shared_ptr<GU::Engin::Frame> frame)
{

}

/*********************************************************************************//**
*   \brief	Clean any resource the state uses
*************************************************************************************/
void TestState::clean(std::shared_ptr<GU::Engin::Frame> frame)
{

}

/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void TestState::handleEvents(GU::Engin::Engin &engin, const float &deltaTime, std::shared_ptr<GU::Engin::Frame> frame)
{
    UNUSED(engin);
    UNUSED(deltaTime); 
}


/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void TestState::update(GU::Engin::Engin &engin, const float &deltaTime, std::shared_ptr<GU::Engin::Frame> frame)
{
    UNUSED(engin);
    UNUSED(deltaTime); 
}


/*********************************************************************************//**
*   \brief	This method draws the current game state.
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void TestState::draw(GU::Engin::Engin &engin, const float &deltaTime, std::shared_ptr<GU::Engin::Frame> frame)
{
    UNUSED(engin);
    UNUSED(deltaTime); 
}


TestState::~TestState()
{

}

class TestFrame: public GU::Engin::Frame
{
    virtual void init() override {};
    virtual void clean() override {};
    virtual void handleEvents(GU::Engin::Engin &engin, const float &deltaTime) override {};
    virtual void update(GU::Engin::Engin &engin, const float &deltaTime) override{};
    virtual void draw(GU::Engin::Engin &engin, const float &deltaTime) override {};
};


TEST_CASE( "Engin class Single argument constructor", "[Engin::Constructor]" ) 
{
    GU::Engin::Engin engin;
    REQUIRE( engin.size() == 0 );
}

TEST_CASE( "Engin class Push method", "[Engin::Push]" ) 
{
    GU::Engin::Engin engin;
    std::shared_ptr<GU::Engin::Frame> myFrame(new TestFrame);
    std::unique_ptr<TestState> state(new TestState);
    
    engin.push(std::move(state), myFrame);
    REQUIRE( engin.size() == 1 );
    
    engin.push<TestState>(myFrame);
    REQUIRE( engin.size() == 2 );
}
