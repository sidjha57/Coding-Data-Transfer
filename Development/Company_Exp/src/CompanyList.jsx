import {Link}  from "react-router-dom";

const CompanyList = ({companies, title, handleDelete}) => {
    // const companys = props.companys; // instead of using this we can destructure the components
    // const title = props.title;

    return ( 
        <div className="company-list">
          <h2>{title}</h2>
            {
              companies.map((company) => (
              <div className="company-preview" key={company.id}> {/*For using react inside map we need to pass unique id */}
                <Link to={`/companies/${company.id}`}>
                  <h2>{company.name}</h2>
                  <p>Role Offered {company.role}</p>
                </Link>
                {/* <button onClick={() => {handleDelete(company.id)}}>Delete</button> */}
              </div>
              
            ))}
        </div>
     );
}
 
export default CompanyList;