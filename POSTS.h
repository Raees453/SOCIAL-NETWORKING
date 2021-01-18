#pragma once
#include"HANDLEFILING.h"
class POSTS :private HANDLEFILING
{
private:
	int postID;
	int postedBy;
	string post;

public:
	POSTS(int a_postedBy = 0, string a_post = "");
	
	void set(int a_postedBy, string a_post);
	
	void displayPosts(int a_id = 0);

	const int getPostID() const;
	const int getPostedByID() const;
	const string getPost() const;
};

