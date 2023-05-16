import { useNavigate, useParams } from "react-router-dom";
import useFetch from "./useFetch";

const CompanyDetails = () => {
    const {id} = useParams();
    const {data: company, error, isPending} = useFetch(`http://localhost:8000/companies/` + id);
    const navigate = useNavigate();

    const handleClick = () => {
        fetch(`http://localhost:8000/companies/` + company.id, {
            method: 'DELETE'
        }).then(() => {
            navigate('/');
        })
    }

    return ( 
        <div className="company-details">
            {isPending && <div>Loading....</div>}
            {error && <div> {error} </div>}
            {company && (
                <airticle>
                    <h2>{company.name}</h2>
                    <p>Role Offered {company.role}</p>
                    <div>{company.body}</div>
                    <button onClick={handleClick}>delete</button>
                </airticle>
            )}
        </div>
     );
}
 
export default CompanyDetails;