//#define BOOST_TEST_DYN_LINK
//#define BOOST_TEST_MAIN
//#include <GameUtilities/Engin/Engin.h>
//#include <GameUtilities/Engin/GameState.h>
//#include <boost/test/unit_test.hpp>
//#include <memory>
//
//class TestState: public GU::Engin::GameState
//{
//	public:
//		TestState(){}
//		        /*********************************************************************************//**
//                *   \brief	Initialize the game state.
//                *************************************************************************************/
//                virtual void Init() {};
//
//                /*********************************************************************************//**
//                *   \brief	Clean any resource the state uses
//                *************************************************************************************/
//                virtual void Clean(){};
//
//                /*********************************************************************************//**
//                *   \brief	This method handles input such as user input and events
//                *	\param	engin is a reference to the game's Engin object.
//                *************************************************************************************/
//                virtual void HandleEvents(GU::Engin::Engin& engin, const int &deltaTime) {};
//
//
//                /*********************************************************************************//**
//                *   \brief	This method handles input such as user input and events
//                *	\param	engin is a reference to the game's Engin object.
//                *************************************************************************************/
//                virtual void Update(GU::Engin::Engin& engin, const int &deltaTime) {};
//
//
//                /*********************************************************************************//**
//                *   \brief	This method draws the current game state.
//                *	\param	engin is a reference to the game's Engin object.
//                *************************************************************************************/
//                virtual void Draw(GU::Engin::Engin& engin, const int &deltaTime) {};
//};
//
//
//
//
////Test default constructors
//BOOST_AUTO_TEST_CASE( Engin_Default_Constructors )
//{
//	GU::Engin::Engin engin;
//
//	//There should not be any states on the stack when
//	BOOST_CHECK(engin.Size() == 0);
//
//	//The game should be running by default
//	BOOST_CHECK(engin.IsRunning());
//}
//
//
//BOOST_AUTO_TEST_CASE( Engin_Move_Constructor )
//{
//
//}
//
//
//BOOST_AUTO_TEST_CASE( Engin_Move_Assignment_operator )
//{
//
//}
//
//
//BOOST_AUTO_TEST_CASE( Engin_Push )
//{
//    GU::Engin::Engin engin;
//
//	//After pushing there should be a single state on the stack
//	engin.Push<TestState>();
//	BOOST_CHECK(engin.Size() == 1);
//
//	//After pushing for a second time there should be two states on the stack
//	engin.Push<TestState>();
//	BOOST_CHECK(engin.Size() == 2);
//
//    while(!engin.empty())
//        engin.Pop();
//
//	//After pushing a state on the stack there should be a single state on the stack
//	std::unique_ptr<TestState> test1(new TestState());
//	engin.Push(std::move(test1));
//	BOOST_CHECK(engin.Size() == 1);
//}
//
//
//BOOST_AUTO_TEST_CASE( Engin_Pop )
//{
//
//}
//
//
//BOOST_AUTO_TEST_CASE( Engin_ChangeState )
//{
//
//}
//
//
//BOOST_AUTO_TEST_CASE( Engin_IsRunning )
//{
//
//}
//
//
//BOOST_AUTO_TEST_CASE( Engin_Quit )
//{
//
//
//}
//
//
//BOOST_AUTO_TEST_CASE( Engin_HandleEvents )
//{
//
//}
//
//
//BOOST_AUTO_TEST_CASE( Engin_Update )
//{
//
//}
//
//
//BOOST_AUTO_TEST_CASE( Engin_Draw )
//{
//
//}
//
//
//BOOST_AUTO_TEST_CASE( Engin_Size )
//{
//
//
//}
//
//
//BOOST_AUTO_TEST_CASE( Engin_Stack_Methods )
//{
//    GU::Engin::Engin engin;
//
//	//After pushing there should be a single state on the stack
//	engin.Push<TestState>();
//	BOOST_CHECK(engin.Size() == 1);
//
//	//After pushing for a second time there should be two states on the stack
//	engin.Push<TestState>();
//	BOOST_CHECK(engin.Size() == 2);
//
//	//After changing state there should be a single state on the stack
//	engin.ChangeState<TestState>();
//	BOOST_CHECK(engin.Size() == 1);
//
//	//After Poping a state from the stack there should be zero states
//	BOOST_CHECK(engin.Pop());	 	//We sould be able to pop a state off stack
//	BOOST_CHECK(engin.Size() == 0);
//
//	//Popping a second time should still result in zero states on the stack
//	BOOST_CHECK(engin.Pop() == false);  //We sould not be able to pop a state off the stack
//	BOOST_CHECK(engin.Size() == 0);
//
//}


