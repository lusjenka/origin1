#pragma once
#ifdef LEAVERLIBRARYDINAMIC_EXPORTS 
#define MATHPOWERLIBRARY_API __declspec(dllexport)
#else
#define MATHPOWERLIBRARY_API __declspec(dllimport)
#endif

	class Leaver
	{
	public:
		void leave(std::string name);
	};
