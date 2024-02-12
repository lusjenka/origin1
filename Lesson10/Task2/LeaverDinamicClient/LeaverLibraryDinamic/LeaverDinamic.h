#pragma once
#ifdef LeaverLibraryDinamic_EXPORTS
#define MATHPOWERLIBRARY_API __declspec(dllexport)
#else
#define MATHPOWERLIBRARY_API __declspec(dllimport)
#endif

	class Leaver
	{
	public:
		MATHPOWERLIBRARY_API void leave(std::string name);
	};
