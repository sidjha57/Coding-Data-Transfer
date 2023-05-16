import React from 'react'
import EditIcon from '../assets/Images/EditIcon.svg'
import DeleteIcon from '../assets/Images/DeleteIcon.svg'
import BlackBagIcon from '../assets/Images/BlackBagIcon.svg'
import { deletePortfolioById, updatePortfolioStatusById } from '../api/Portfolio';
import { addDataIntoCache } from '../js/caching';
import { useNavigate, useSearchParams } from 'react-router-dom';
import { PortfolioType } from '../interface/Portfolio';
import LongShortInstrument from './LongShortInstrument';
import { updateAppState } from '../lib/appState';
import { InstrumentType } from '../interface/Intrument';
import { frontendUrl } from '../js/urls';
import moment from 'moment';
import { ContestType } from '../interface/Contest';

interface SavedPortfolioProps {
    setSavedPortfolios: any
    setJoinedPortfolios: any
    portfolios: PortfolioType[]
    joined: PortfolioType[]
    isDisabled: boolean
    setIsDisabled: any
    contest: ContestType
}


const SavedPortfolio = ({ setSavedPortfolios, setJoinedPortfolios, portfolios, joined, isDisabled, setIsDisabled, contest }: SavedPortfolioProps) => {

    const appStateKey = 1;
    const navigate = useNavigate();
    // const [error, setError] = React.useState(""); 
    let count = 1;
    const [searchParams, setSearchParams] = useSearchParams();

    // console.log(portfolios)

    const handleEdit = async (saved: PortfolioType) => {

        const selectedInstruments: InstrumentType[] = saved.portfolioSelections.map((instruments) => {

            return {
                ipid: instruments.instrument.ipid,
                instrumentName: instruments.instrument.instrumentName,
                instrumentSymbol: instruments.instrument.instrumentSymbol,
                isActive: 1,
                instrumentSelection: instruments.instrumentSelection === 1 ? "Long" : "Short",
                boosterSelection: instruments.boosterSelection
            }
        });

        console.log(selectedInstruments);
        await updateAppState({ selectedInstruments }, appStateKey)
        await addDataIntoCache("EditState", frontendUrl, { edit: true, portfolioId: saved.ipid, statusId: saved.status.ipid })
        navigate({
            pathname: '/instruments',
            search: searchParams.toString()
        }, { state: { contest: contest, contestParameterId: 1 } })
    }

    const handleDelete = async (id: number) => {
        setSavedPortfolios(
            portfolios.filter((portfolio) => portfolio.ipid !== id)
        )
        try {
            await deletePortfolioById(id);
        } catch (err) {
            console.log(err);
        }
    }

    const handleJoin = async (saved: PortfolioType) => {
        // Check for the limit of 5 joined portfolios needs to be written
        setSavedPortfolios(
            portfolios.filter((portfolio) => portfolio.ipid !== saved.ipid)
        )

        const updatedJoined = [...joined, saved];

        if (updatedJoined.length >= 5) {
            setIsDisabled(true);
        }

        setJoinedPortfolios(updatedJoined)

        try {
            await updatePortfolioStatusById(saved.status.ipid, "JOINED");
        } catch (err) {
            console.log(err);
        }

    }


    return (

        <div className='h-[132px] '>
            {
                portfolios &&
                portfolios.map((saved: PortfolioType, index) => (
                    <div key={saved.ipid} className="border  rounded-md m-4 bg-white ">
                        <div className="grid grid-flow-col h-[108px]  p-3 ">

                            <div className="grid w-[224px]">
                                <div className="grid grid-flow-col place-content-start align-middle gap-1 ">
                                    <img className='h-5 w-5 p-[2.5px]' src={BlackBagIcon} alt="" />
                                    <span className='font-semibold text-sm text-[#47464A] text-center'>Saved Portfolio{count++}</span>
                                </div>
                                <div className='text-xs my-3 '>
                                    <LongShortInstrument portfolioSelections={saved?.portfolioSelections} />
                                </div>
                            </div>

                            <div className="grid align-middle place-items-end">

                                <button
                                    disabled={isDisabled}
                                    className={`cursor-pointer text-xs font-bold text-[#08309E] bg-white text-center mb-7  h-7 w-14 border border-[#08309E] rounded-sm ${isDisabled ? 'text-[#C8C6CA] border-[#C8C6CA]' : ''
                                        }`} onClick={() => handleJoin(saved)}>
                                    Join
                                </button>
                            </div>



                        </div>

                        <div className='grid grid-flow-col gap-[1px]'>
                            <button onClick={() => handleEdit(saved)} className='cursor-pointer h-6 grid grid-flow-col place-content-center place-items-center gap-1 bg-[#F5F5F5] rounded-bl-md'>

                                <img className='h-3 w-3' src={EditIcon} alt="" />
                                <div className='text-xs text-light-text '>Edit</div>
                            </button>
                            <button onClick={() => handleDelete(saved.ipid)} className='cursor-pointer h-6 grid grid-flow-col place-items-center place-content-center gap-1 bg-[#F5F5F5] rounded-br-md'>
                                <div>
                                    <img className='h-3 w-3' src={DeleteIcon} alt="" />
                                </div>
                                <div className='text-xs text-light-text ' >Delete</div>
                            </button>
                        </div>
                    </div>
                ))
            }

        </div>
    )
}

export default SavedPortfolio