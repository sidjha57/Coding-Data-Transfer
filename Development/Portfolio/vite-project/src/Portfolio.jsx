import React from 'react';
import resume from './resume.json';
import './Portfolio.css';

function Portfolio() {
  
  return (
    <div className="container mx-auto py-8 px-4">
      <h1 className="text-4xl font-bold mb-4">{resume.name}</h1>
      <p className="text-lg mb-4">{resume.title}</p>
      <div className="flex flex-wrap">
        <div className="w-full md:w-1/2 lg:w-1/3 mb-4 px-4">
          <h2 className="text-lg font-bold mb-2">Contact Information</h2>
          <ul>
            <li>Email: {resume.email}</li>
            <li>Mobile: {resume.mobile}</li>
            <li>LinkedIn: <a href={resume.linkedin}>{resume.linkedin}</a></li>
            <li>Github: <a href={resume.github}>{resume.github}</a></li>
          </ul>
        </div>
        <div className="w-full md:w-1/2 lg:w-1/3 mb-4 px-4">
          <h2 className="text-lg font-bold mb-2">Education</h2>
          <p>{resume.education.degree}</p>
          <p>{resume.education.institution}</p>
          <p>CGPA: {resume.education.cgpa}</p>
          <p>{resume.education.dateRange}</p>
        </div>
        <div className="w-full md:w-1/2 lg:w-1/3 mb-4 px-4">
          <h2 className="text-lg font-bold mb-2">Internship Experiences</h2>
          {resume.internships.map((internship, index) => (
            <div key={index} className="mb-4">
              <h3 className="text-md font-bold">{internship.role}</h3>
              <p className="text-sm font-bold">{internship.company}</p>
              <p>{internship.dateRange}</p>
              <ul className="list-disc list-inside">
                {internship.responsibilities.map((task, index) => (
                  <li key={index}>{task}</li>
                ))}
              </ul>
            </div>
          ))}
        </div>
      </div>
    </div>
  );
}

export default Portfolio;
