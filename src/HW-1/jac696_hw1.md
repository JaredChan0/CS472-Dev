Name: Jared Chandavong <jac696>
Assignment: HW-1
Date: 01/17/2025

===========================================================

Prompt:Lets attempt to design our own custom application protocol for
a hypothetical course registration system used by a university. The 
protocol should include mechanisms for students to register for 
courses, for instructors to approve or deny course registration 
requests, and for the registrar's office to manage course enrollment 
limits and waitlists.


(1) Addressing/Identity
Questions:
- (a) How will the system handle temporary or guest users, such as 
      substitute/temporary instructors or exchange students, who need 
      limited access to course information or registration features?

Answers:
- (a) For temporary or guest users, the registrar's office will issue 
      guest credentials with limited access, tailored to their respective 
      needs. For example, guest instructors/speakers or substitutes may 
      have read-only access to the course catalog to review their assigned 
      courses. Exchange students may have access to register for courses 
      within a specific department or as part of a program. These guest 
      users would be managed directly by the registrar's office, only 
      allowing them to interact with the system with restricted access 
      that's time-limited depeneding on their circumstances (i.e. valid 
      for the duration of the exchange program, or for how long they will
      be present in the term). Upon expiration, these guest credentials would 
      either be automatically revoked or manually changed by the registrar's 
      office.

===========================================================

(2) Messaging
Questions:
- (a) How will the system dictate whether a client meets the requirements
  to register/apply for a course?
- (b) How will the system present to the client their planned registered 
  courses?

Answers:
- (a) When a client is on the registration screen for courses, they'll be
      presented with a list of available courses for the term that can be
      filtered out via search queries. In the case of a student, they would
      search for a specific course and then be presented with various tabs
      of clearly named details for the course, i.e. previously completed
      classes, specific timeslots, linked sections, and available seats. 
      If a student tries to register for the course within these parameters,
      then their registration would be updated with a visible timesheet for
      that course and section. However, if the student tried to do so without
      the necessary filled out, then they will receive a popup notification 
      indicating that the registration action cannot be done and the reason why.
      An instructor would be able to see the courses and sections that
      they will be specifically teaching those terms and could request for certain
      requirement changes, which may include changing of locations, timeslots
      and such. The registrar's office would then look over the request, go 
      into the course details, and handle the changes. They would be be able to
      override any changes themselves, if needed.

===========================================================

(3) State
Questions:
- (a) What is the general order of events that a client would take during 
      the registration process?
- (b) How are transitions handled when a client is added to the waitlist 
      or when a course becomes full?

Answers:
- (b) If a course is full, then the registered student is automatically 
      transitioned into a waitlist status. If a seat opens up, then an 
      employee at the registrar's office will hold the seat for the 
      first person in the waitlist. They will then send a notification to that student informing them that they have the opportunity to change from
      the waitlist state to the enrolled state. The student will have the
      option to confirm or decline enrollment. Confirming will do as mentioned
      previously, but declining or missing the timeframe will transition the
      student from the waitlisted state to a "not enrolled" state for that
      course. An instructor, during these scenarios, would then overlook the
      request to either approve or deny the student's enrollment.

===========================================================

(4) Error Handling and Recovery
Questions:
- (a) What happens when a specific course/section is closed for registration?
- (b) What happens when a registered course/section gets cancelled?

Answers:
- (b) If an university were to cancel a course that was expected to be held
      in the next term, some possible explanations can include, but not limited to,
      low enrollment, absence of available instructors, and restructuring of 
      departments. For a student, the situation changes drastically depending on
      whether or not the cancelled registered course was required. Simply put,
      if the course was not required for the student, the student would have to
      find another course to fill that spot for the term. However, should said
      course be a required one, then the student would have to contact their
      academic advisors. In this case, the registrar's office will be able to go
      into the student's registration files and can either override the student's
      course profile and allow them to register for a substitution course to
      replace that required one. As mentioned above for whatever reasons that a
      registered course could be cancelled, the instructor would be the one to have
      the option to request for a course cancellation from the registrar's offfice.

===========================================================

(5) Security
Questions:
- (a) How can a client trust or validate that the registration system is
      owned by the university?
- (b) How does the system ensure that a student cannot manipulate their 
      course registration?

Answers:
- (a) For all intents and purposes, all university internal related websites 
      and applications should be running in a private domain that can only 
      be accessed by those with valid credentials. As such, every instructor
      and employee in the registrar's office should have workstations or
      university computers automatically wired to the university's domain so that
      any website or program used by the university is valid. Furthermore,
      given that they would have experience and knowledge about this, they should
      be able to recognize the correct domain when using personal devices. In
      the case for students, however, they wouldn't have such recognition, so
      they would have to find various notes or indicators that would validate 
      the university. For example, checking the URL name to see if it has the
      university's web domain, which is usually the university's name followed
      but ".edu". Furthermore, the student can check to see if the website for the
      registration system has the university's branding logo and a dedicated login
      section/profile page. Especially given how many universities have users/clients
      remain logged in for a given period through a dedicated login system that
      automatically logs them into other university applications and services, 
      if the registration page doesn't have the student logged in or any of the
      previously mentioned things, then they can determine if it can be trusted or
      not.