//enum to compare the hand they have
typedef enum {
	nothing,
	one_pair,
	two_pair,
	three_of_a_kind,
	straight,
	flush,
	full_house,
	four_of_a_kind,
	straight_flush,
	royal_flush}bestHand;

//enum for the suit each card has
typedef enum {
	heart,
	spades,
	clubs,
	diamonds}suit;
//struct of a card containing a value and a suit
typedef struct card{
	int val;
	suit  card_suit;
} CARD;

//player stuct with 2 cards, and the strength of his hand
typedef struct Player{
	bestHand hand;
	CARD card1;
	CARD card2;
} PLAYER;


bool whichPlayerWon(PLAYER[] players);

