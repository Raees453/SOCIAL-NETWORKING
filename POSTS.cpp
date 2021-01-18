#include "POSTS.h"

POSTS::POSTS(int a_postedBy, string a_post)
{
	set(a_postedBy, a_post);
}

void POSTS::set(int a_postedBy, string a_post)
{
	fstream dataFile;
	postID = this->getLastID(dataFile, "posts.txt");
	post = a_post;
	postedBy = a_postedBy;
	this->insertPost(postID, postedBy, post);
}

void POSTS::displayPosts(int a_id)
{
	this->showPosts(a_id);
}

const int POSTS::getPostID() const
{
	return postID;
}

const int POSTS::getPostedByID() const
{
	return postedBy;
}

const string POSTS::getPost() const
{
	return post;
}
