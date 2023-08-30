#ifndef CHESSGAME_H
#define CHESSGAME_H

class ChessGame
{
	const size_t SIZE{8};
	const std::string PIECE_ROW_MESSAGE{"Enter the piece row: "};
	const std::string PIECE_COL_MESSAGE{"Enter the piece col: "};
	const std::string MOVE_ROW_MESSAGE{"Move piece to row: "};
	const std::string MOVE_COL_MESSAGE{"Move piece to col: "};
	
	public:
		
		explicit ChessGame();
		void DisplayChessBoard() const;
		
		short PromptMessage(const std::string&);
		bool isPositionValid() const;
		
		void CheckSelectedPiece(const std::string&);
		
		void runGame();
		
	private:
		
		const void WelcomeMessage();
		
		enum class Players{WHITE, BLACK};
		Players activePlayer{Players::WHITE};
		
		enum class WhitePiece{WP, WR, WN, WB, WK, WQ};
		enum class BlackPiece{BP, BR, BN, BB, BK, BQ};
		
		std::string board[8][8] = {
			{"BR", "BN", "BB", "BK","BQ", "BB", "BN", "BR"},
			{"BP", "BP", "BP", "BP","BP", "BP", "BP", "BP"},
			{"..", "..", "..", "..", "..", "..", "..", ".."},
			{"..", "..", "..", "..", "..", "..", "..", ".."},
			{"..", "..", "..", "..", "..", "..", "..", ".."},
			{"..", "..", "..", "..", "..", "..", "..", ".."},
			{"WP", "WP", "WP", "WP","WP", "WP", "WP", "WP"},
			{"WR", "WN", "WB", "WK","WQ", "WB", "WN", "WR"}
		};
};

#endif
