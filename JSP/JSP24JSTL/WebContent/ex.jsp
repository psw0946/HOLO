<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=EUC-KR">
<title>Insert title here</title>
</head>
<body>

	<c:set var="varName" value="varValue" />
	varName : <c:out value="${varName }" /> <br />
	
	<c:remove var="varName" />
	varName : <c:out value="${varName }" /> <!-- 값이 remove돼서 출력되지 않음 -->
	
	<c:forEach var="fe" begin="0" end="100" step="5">
		${fe } <br/>
	</c:forEach>

</body>
</html>