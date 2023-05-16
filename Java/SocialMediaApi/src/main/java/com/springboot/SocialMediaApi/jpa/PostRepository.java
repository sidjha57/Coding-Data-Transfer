package com.springboot.SocialMediaApi.jpa;

import com.springboot.SocialMediaApi.post.Post;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface PostRepository extends JpaRepository<Post, Integer> {
}
