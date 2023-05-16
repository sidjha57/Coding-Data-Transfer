import React from 'react'

const Menu = () => {
  const posts = [
    {
      id: 1,
      role: "Associate Software Engineer",
      company: "Capgemini",
      ctc: 8,
      college: "Sardar Patel College Of Engineering",
      type: "On Campus",
      experience: "Positive",
      status: "Accepted",
      level: "Easy",
      desc: "Lorem, ipsum dolor sit amet consectetur adipisicing elit. A possimus excepturi aliquid nihil cumque ipsam facere aperiam at! Ea dolorem ratione sit debitis deserunt repellendus numquam ab vel perspiciatis corporis!",
      img: "https://images.pexels.com/photos/7008010/pexels-photo-7008010.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=2",
    },
    {
      id: 2,
      role: "Finance Head",
      company: "Axella",
      ctc: 14,
      college: "SPCE",
      type: "On Campus",
      experience: "Negative",
      status: "No",
      level: "Difficult",
      desc: "Lorem, ipsum dolor sit amet consectetur adipisicing elit. A possimus excepturi aliquid nihil cumque ipsam facere aperiam at! Ea dolorem ratione sit debitis deserunt repellendus numquam ab vel perspiciatis corporis!",
      img: "https://images.pexels.com/photos/6489663/pexels-photo-6489663.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=2",
    },
    {
      id: 3,
      role: "Data Analyst",
      company: "Axis Bank",
      ctc: 8,
      college: "SPCE",
      type: "On Campus",
      experience: "Average",
      status: "Rejected",
      level: "Easy",
      desc: "Lorem, ipsum dolor sit amet consectetur adipisicing elit. A possimus excepturi aliquid nihil cumque ipsam facere aperiam at! Ea dolorem ratione sit debitis deserunt repellendus numquam ab vel perspiciatis corporis!",
      img: "https://images.pexels.com/photos/4230630/pexels-photo-4230630.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=2",
    },
    {
      id: 4,
      role: "Software Engineer",
      company: "Carwale",
      ctc: 10,
      college: "SPCE",
      type: "On Campus",
      experience: "Positive",
      status: "No",
      level: "Difficult",
      desc: "Lorem, ipsum dolor sit amet consectetur adipisicing elit. A possimus excepturi aliquid nihil cumque ipsam facere aperiam at! Ea dolorem ratione sit debitis deserunt repellendus numquam ab vel perspiciatis corporis!",
      img: "https://images.pexels.com/photos/6157049/pexels-photo-6157049.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=2",
    },
  ];

  return (
    <div className='menu'>
      <h1>Other posts you may like</h1>
      {posts.map((post) => (
        <div className="post" key={post.id}>
          <img src={post.img} alt="" />
          <h2>{post.role}</h2>
          <div className="last"> 
            <button>Read More</button>
            <span>{post.company}</span>
          </div>
        </div>
      ))}
    </div>
  )
}

export default Menu