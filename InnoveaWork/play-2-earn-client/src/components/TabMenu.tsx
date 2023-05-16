import React from "react"
import { useLocation, useNavigate, useSearchParams } from "react-router-dom"

interface tabMenu {
  name: string
  isSelected: boolean
  changeHandler: (name: string) => void
}

function TabMenu({ name, isSelected, changeHandler }: tabMenu) {
  function classNames(...classes: any[]) {
    return classes.filter(Boolean).join(" ")
  }

  const navigate = useNavigate()
  const {pathname} = useLocation()
  const [searchParams, setSearchParams ] = useSearchParams()

  return (
    <div className="">
      <button
        onClick={() => {
          const contestType : string = name.toLowerCase()
          searchParams.set('contestType' , contestType)
          setSearchParams(searchParams)
          navigate({
            // pathname: pathname,
            search : searchParams.toString()
          })
          changeHandler(name)
        }}
        className={classNames(
          isSelected
          ? " text-[#08309E]"
          : " text-[#77767A]",
            " h-8 text-sm font-medium capitalize"
          )}
          aria-current={isSelected ? "page" : undefined}
          >
          {name}
      </button>
      <div style={{backgroundColor : isSelected ? "#08309E" : "" }} className="h-[3px] w-[60px]  rounded-tl-full rounded-tr-full"></div>
    </div>

  )
}

export default TabMenu
